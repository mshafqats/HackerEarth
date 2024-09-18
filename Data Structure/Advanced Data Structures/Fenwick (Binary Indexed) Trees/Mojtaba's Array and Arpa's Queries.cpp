/*
=====================
|  ID:   mshafqats  |
|  LANG: C++        |
=====================
Mohammad Shafqat Siddiqui
*/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
 
template<typename T>
struct RMQ {
    int n = 0, levels = 0;
    vector<vector<T>> range_min;
 
    RMQ(const vector<T> &values = {}) {
        if (!values.empty())
            build(values);
    }
 
    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }
 
    void build(const vector<T> &values) {
        n = values.size();
        levels = largest_bit(n) + 1;
        range_min.resize(levels);
 
        for (int k = 0; k < levels; k++)
            range_min[k].resize(n - (1 << k) + 1);
 
        for (int i = 0; i < n; i++)
            range_min[0][i] = values[i];
 
        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_min[k][i] = min(range_min[k - 1][i], range_min[k - 1][i + (1 << (k - 1))]);
    }
 
    T query(int a, int b) const {
        assert(a < b);
        int level = largest_bit(b - a);
        return min(range_min[level][a], range_min[level][b - (1 << level)]);
    }
};
 
const int INF = 1e9 + 5;
 
int N, K, Q, P;
vector<int> primes;
vector<int> k_powers;
vector<int> A;
 
void factor_K() {
    for (int p = 2; p * p <= K; p++)
        if (K % p == 0) {
            primes.push_back(p);
            int power = 0;
 
            do {
                K /= p;
                power++;
            } while (K % p == 0);
 
            cerr << p << ' ' << power << endl;
            k_powers.push_back(power);
        }
 
    if (K > 1) {
        primes.push_back(K);
        k_powers.push_back(1);
        K = 1;
    }
 
    P = primes.size();
}
 
vector<int> powers;
 
void add(int number, int change) {
    for (int i = 0; i < P; i++)
        while (number % primes[i] == 0) {
            number /= primes[i];
            powers[i] += change;
        }
}
 
bool sufficient() {
    for (int i = 0; i < P; i++)
        if (powers[i] < k_powers[i])
            return false;
 
    return true;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> N >> K >> Q;
    factor_K();
    A.resize(N);
 
    for (int i = 0; i < N; i++)
        cin >> A[i];
 
    powers.resize(P);
    vector<int> endpoint(N);
 
    for (int i = 0, j = 0; i < N; i++) {
        while (j < N && !sufficient())
            add(A[j++], +1);
 
        endpoint[i] = sufficient() ? j : INF;
        add(A[i], -1);
    }
 
    vector<int> lengths(N);
 
    for (int i = 0; i < N; i++)
        lengths[i] = endpoint[i] - i;
 
    RMQ<int> rmq(lengths);
 
    for (int q = 0; q < Q; q++) {
        int L, R;
        cin >> L >> R;
        L--;
 
        int low = L, high = R;
 
        while (low < high) {
            int mid = (low + high) / 2;
 
            if (endpoint[mid] > R)
                high = mid;
            else
                low = mid + 1;
        }
 
        int answer;
 
        if (low == L)
            answer = -1;
        else
            answer = rmq.query(L, low);
 
        if (answer >= INF / 2)
            answer = -1;
 
        cout << answer << (q < Q - 1 ? ' ' : '\n');
    }
}
