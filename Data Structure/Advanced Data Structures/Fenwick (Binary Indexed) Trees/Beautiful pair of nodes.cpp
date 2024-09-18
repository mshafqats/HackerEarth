/*
=====================
|  ID:   mshafqats  |
|  LANG: C++        |
=====================
Mohammad Shafqat Siddiqui
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << "\n";
#define endl "\n";
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
template<class T = int> struct bit2d {
	vector<T> X;
	vector<vector<T>> Y, t;
 
	int ub(vector<T>& v, T x) {
		return upper_bound(v.begin(), v.end(), x) - v.begin();
	}
	bit2d(vector<pair<T, T>> v) {
		for (auto [x, y] : v) X.push_back(x);
		sort(X.begin(), X.end());
		X.erase(unique(X.begin(), X.end()), X.end());
 
		t.resize(X.size() + 1);
		Y.resize(t.size());
		sort(v.begin(), v.end(), [](auto a, auto b) {
			return a.second < b.second; });
		for (auto [x, y] : v) for (int i = ub(X, x); i < t.size(); i += i&-i)
			if (!Y[i].size() or Y[i].back() != y) Y[i].push_back(y);
 
		for (int i = 0; i < t.size(); i++) t[i].resize(Y[i].size() + 1);
	}
 
	void update(T x, T y, T v) {
		for (int i = ub(X, x); i < t.size(); i += i&-i)
			for (int j = ub(Y[i], y); j < t[i].size(); j += j&-j) t[i][j] += v;
	}
 
	T query(T x, T y) {
		T ans = 0;
		for (int i = ub(X, x); i; i -= i&-i)
			for (int j = ub(Y[i], y); j; j -= j&-j) ans += t[i][j];
		return ans;
	}
	T query(T x1, T y1, T x2, T y2) {
		return query(x2, y2)-query(x2, y1-1)-query(x1-1, y2)+query(x1-1, y1-1);
	}
};
 
void solve() {
    int n; cin >> n;
 
    vector<vector<int>> graph(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
 
    vector<pair<int,int>> a_p(n), b_p(n);
    vector<int> a(n), b(n);
 
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a_p[i] = {x,i};
    }
    sort(a_p.begin(), a_p.end());
    int nx = 1;
    for (int i = 0; i < n; i++) {
        if (i > 0 && a_p[i-1].first != a_p[i].first) nx++;
        a[a_p[i].second] = nx;
    }
 
    for (int i = 0;i < n; i++) {
        int x; cin >> x;
        b_p[i] = {x,i};
    }
    sort(b_p.begin(),b_p.end());
    nx = 1;
    for (int i = 0; i < n; i++) {
        if (i > 0 && b_p[i-1].first != b_p[i].first) nx++;
        b[b_p[i].second] = nx;
    }
 
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++)
        v[i] = {a[i], b[i]};
 
    bit2d bit(v);
    vector<bool> vis(n,false);
 
    stack<pair<int,int>> s;
    s.emplace(0,0);
 
    ll ans = 0;
    while(!s.empty()) {
        auto [u,st] = s.top(); s.pop();
        
        if (!st) {
            if(vis[u]) continue;
            vis[u] = true;
 
            ans += bit.query(a[u]-1, b[u]-1);
            bit.update(a[u], b[u], 1);
            s.emplace(u,1);
 
            for (auto &v: graph[u]) if (!vis[v])
                s.emplace(v,0);
        }
        else {
            bit.update(a[u], b[u], -1);
        }
    }
    cout << ans << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
