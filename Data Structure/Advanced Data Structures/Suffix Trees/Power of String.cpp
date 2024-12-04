/*
=====================
|  ID:   mshafqats  |
|  LANG: C++        |
=====================
Mohammad Shafqat Siddiqui
*/

#include <iostream> 
#include <iomanip>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <map>
#include <bitset>
#include <set>
#include <stack>
#include <numeric>
#include <unordered_map>
#include <random>
using namespace std;
using ll = long long;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
using vb = vector<bool>; using vvb = vector<vb>;
using vd = vector<double>; using vvd = vector<vd>;
using vs = vector<string>;
using pii = pair<int, int>; using vpii = vector<pii>;
using pil = pair<int, ll>; using vpil = vector<pil>;
using pll = pair<ll, ll>; using vpll = vector<pll>;
using pdd = pair<double, double>; using vpdd = vector<pdd>;
const int inf = (1 << 30) - 1;
const ll INF = 1LL << 60;
const int MOD = 998244353;
template<typename T> inline bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true) : (false)); }
 
template<class MeetSemiLattice> struct SparseTable {
	vector<vector<MeetSemiLattice> > dat;
	vector<int> height;
 
	SparseTable() {}
	SparseTable(const vector<MeetSemiLattice>& vec) { init(vec); }
	void init(const vector<MeetSemiLattice>& vec) {
		int n = (int)vec.size(), h = 1;
		while ((1 << h) < n) ++h;
		dat.assign(h, vector<MeetSemiLattice>(1 << h));
		height.assign(n + 1, 0);
		for (int i = 2; i <= n; i++) height[i] = height[i >> 1] + 1;
		for (int i = 0; i < n; ++i) dat[0][i] = vec[i];
		for (int i = 1; i < h; ++i)
			for (int j = 0; j < n; ++j)
				dat[i][j] = min(dat[i - 1][j], dat[i - 1][min(j + (1 << (i - 1)), n - 1)]);
	}
 
	MeetSemiLattice get(int a, int b) {
		return min(dat[height[b - a]][a], dat[height[b - a]][b - (1 << height[b - a])]);
	}
};
 
template<class Str> struct SuffixArray {
	Str str;
	vector<int> sa;
	vector<int> rank;
	vector<int> lcp;
	SparseTable<int> st;
	int& operator [] (int i) { return sa[i]; }
	const int& operator [] (int i) const { return sa[i]; }
	vector<int> get_sa() { return sa; }
	vector<int> get_rank() { return rank; }
	vector<int> get_lcp() { return lcp; }
	SuffixArray() {}
	SuffixArray(const Str& str_, bool no_limit_elements = false) : str(str_) {
		build_sa(no_limit_elements);
	}
	void init(const Str& str_, bool no_limit_elements = false) {
		str = str_;
		build_sa(no_limit_elements);
	}
	void build_sa(bool no_limit_elements = false) {
		vector<int> s;
		int num_of_chars = 256;
		if (!no_limit_elements) {
			for (int i = 0; i < (int)str.size(); ++i) {
				s.push_back(str[i] + 1);
			}
		}
		else {
			unordered_map<int, int> dict;
			for (int i = 0; i < (int)str.size(); ++i) {
				if (!dict.count(str[i])) dict[str[i]] = dict.size();
			}
			for (int i = 0; i < (int)str.size(); ++i) {
				s.push_back(dict[str[i]] + 1);
			}
			num_of_chars = (int)dict.size();
		}
		s.push_back(0);
		sa = sa_is(s, num_of_chars);
		build_lcp(s);
		build_sparse_table();
	}

	vector<int> sa_is(vector<int>& s, int num_of_chars) {
		int N = (int)s.size();
		if (N == 0) return {};
		else if (N == 1) return { 0 };
		else if (N == 2) {
			if (s[0] < s[1]) return { 0, 1 };
			else return { 1, 0 };
		}
 
		vector<int> isa(N);
		vector<bool> ls(N, false);
		for (int i = N - 2; i >= 0; --i) {
			ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
		}
		vector<int> sum_l(num_of_chars + 1, 0), sum_s(num_of_chars + 1, 0);
		for (int i = 0; i < N; ++i) {
			if (!ls[i]) ++sum_s[s[i]];
			else ++sum_l[s[i] + 1];
		}
		for (int i = 0; i <= num_of_chars; ++i) {
			sum_s[i] += sum_l[i];
			if (i < num_of_chars) sum_l[i + 1] += sum_s[i];
		}
 
		auto induce = [&](const vector<int>& lms) -> void {
			fill(isa.begin(), isa.end(), -1);
			vector<int> buf(num_of_chars + 1);
			copy(sum_s.begin(), sum_s.end(), buf.begin());
			for (auto d : lms) {
				if (d == N) continue;
				isa[buf[s[d]]++] = d;
			}
			copy(sum_l.begin(), sum_l.end(), buf.begin());
			isa[buf[s[N - 1]]++] = N - 1;
			for (int i = 0; i < N; ++i) {
				int v = isa[i];
				if (v >= 1 && !ls[v - 1]) {
					isa[buf[s[v - 1]]++] = v - 1;
				}
			}
			copy(sum_l.begin(), sum_l.end(), buf.begin());
			for (int i = N - 1; i >= 0; --i) {
				int v = isa[i];
				if (v >= 1 && ls[v - 1]) {
					isa[--buf[s[v - 1] + 1]] = v - 1;
				}
			}
		};
 
		vector<int> lms, lms_map(N + 1, -1);
		int M = 0;
		for (int i = 1; i < N; ++i) {
			if (!ls[i - 1] && ls[i]) {
				lms_map[i] = M++;
			}
		}
		lms.reserve(M);
		for (int i = 1; i < N; ++i) {
			if (!ls[i - 1] && ls[i]) {
				lms.push_back(i);
			}
		}
		induce(lms);
 
		if (M) {
			vector<int> lms2;
			lms2.reserve(isa.size());
			for (auto v : isa) {
				if (lms_map[v] != -1) lms2.push_back(v);
			}
			int rec_upper = 0;
			vector<int> rec_s(M);
			rec_s[lms_map[lms2[0]]] = 0;
			for (int i = 1; i < M; ++i) {
				int l = lms2[i - 1], r = lms2[i];
				int nl = (lms_map[l] + 1 < M) ? lms[lms_map[l] + 1] : N;
				int nr = (lms_map[r] + 1 < M) ? lms[lms_map[r] + 1] : N;
				bool same = true;
				if (nl - l != nr - r) same = false;
				else {
					while (l < nl) {
						if (s[l] != s[r]) break;
						++l, ++r;
					}
					if (l == N || s[l] != s[r]) same = false;
				}
				if (!same) ++rec_upper;
				rec_s[lms_map[lms2[i]]] = rec_upper;
			}
			auto rec_sa = sa_is(rec_s, rec_upper);
 
			vector<int> sorted_lms(M);
			for (int i = 0; i < M; ++i) {
				sorted_lms[i] = lms[rec_sa[i]];
			}
			induce(sorted_lms);
		}
		return isa;
	}
 
	int lower_bound(const Str& T) {
		int left = -1, right = sa.size();
		while (right - left > 1) {
			int mid = (left + right) / 2;
			if (str.compare(sa[mid], string::npos, T) < 0)
				left = mid;
			else
				right = mid;
		}
		return right;
	}
 
	int upper_bound(const Str& T) {
		int left = -1, right = sa.size();
		while (right - left > 1) {
			int mid = (left + right) / 2;
			if (str.compare(sa[mid], T.size(), T) <= 0)
				left = mid;
			else
				right = mid;
		}
		return right;
	}

	int lower_bound(int l, int r) {
		int left = -1, right = rank[l];
		while (right - left > 1) {
			int mid = (left + right) / 2;
			if (st.get(mid, rank[l]) < r - l) left = mid;
			else right = mid;
		}
		return right;
	}
 
	bool is_contain(const Str& T) {
		int lb = lower_bound(T);
		if (lb >= sa.size()) return false;
		return str.compare(sa[lb], T.size(), T) == 0;
	}

	void build_lcp(const vector<int>& s) {
		int N = (int)s.size();
		rank.assign(N, 0), lcp.assign(N - 1, 0);
		for (int i = 0; i < N; ++i) rank[sa[i]] = i;
		int h = 0;
		for (int i = 0; i < N - 1; ++i) {
			int pi = sa[rank[i] - 1];
			if (h > 0) --h;
			for (; pi + h < N && i + h < N; ++h) {
				if (s[pi + h] != s[i + h]) break;
			}
			lcp[rank[i] - 1] = h;
		}
	}

	void build_sparse_table() {
		st.init(lcp);
	}

	int get_lcp(int a, int b) {
		return st.get(min(rank[a], rank[b]), max(rank[a], rank[b]));
	}

	void dump() {
		for (int i = 0; i < sa.size(); ++i) {
			cout << i << ": " << sa[i] << ", " << str.substr(sa[i]) << endl;
		}
	}
};
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int k, n;
	string s;
	cin >> k >> n >> s;
	SuffixArray suf(s);
	int l = 0;
	int r = n + 1;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		int ma = 0;
		int cnt = 0;
		for (int i = 0; i < suf.lcp.size(); i++) {
			if (suf.lcp[i] >= mid) {
				cnt++;
			}
			else {
				chmax(ma, cnt);
				cnt = 0;
			}
		}
		chmax(ma, cnt);
		if (ma >= k - 1) l = mid;
		else r = mid;
	}
	cout << l << endl;
	return 0;
}
