/*
=====================
|  ID: mshafqats    |
|  LANG: C++        |
=====================
Mohammad Shafqat Siddiqui
*/

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const ll MOD = 1000000021;
const ll ROOT3 = 589781815;
const ll IOTA = 484563811;
 
ll modexp(ll x, ll n) {
    if (n == 0) return 1ll;
    if (n == 1) return x % MOD;
    ll y = modexp(x, n / 2);
    y = (y * y) % MOD;
    return (n % 2 == 0) ? y : (y * x) % MOD;
}
 
ll add(ll x, ll y) {
    return ((x % MOD + y % MOD) % MOD + MOD) % MOD;
}
 
ll sub(ll x, ll y) {
    return ((x % MOD - y % MOD) % MOD + MOD) % MOD;
}
 
ll mul(ll x, ll y) {
    return (x % MOD * y % MOD) % MOD;
}
 
ll divide(ll x, ll y) {
    return (x % MOD * modexp(y % MOD, MOD - 2)) % MOD;
}
 
ll helper(ll z, ll n) {
    z %= MOD;
    ll x = sub(mul(n % MOD, z), 1ll);
    x = mul(x, modexp(add(z, 1ll), n));
    x = add(x, 1ll);
    return divide(x, mul(add(n % MOD, 1ll), mul(z, z)));
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll t;
    cin >> t;
    assert(1 <= t && t <= 100000);
 
    while (t--) {
        ll n, k;
        cin >> n >> k;
        assert(1 <= n && n <= 1000000000000000000ll);
        assert(0 <= k && k <= 1000000000000000000ll);
 
        if (n == 1) {
            cout << "0\n";
            continue;
        }
 
        ll r3ik = mul(mul(ROOT3, IOTA), k % MOD);
        ll op_r3ik = add(1ll, r3ik);
        ll om_r3ik = sub(1ll, r3ik);
        ll pre = mul(r3ik, modexp(2ll, n - 2));
 
        ll a1 = helper(divide(op_r3ik, 2ll), n);
        ll a2 = helper(divide(om_r3ik, 2ll), n);
 
        ll ans = mul(pre, sub(a1, a2));
 
        cout << ans << "\n";
    }
 
    return 0;
}
