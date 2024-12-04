/*
=====================
|  ID:   mshafqats  |
|  LANG: C++        |
=====================
Mohammad Shafqat Siddiqui
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>
#include <iomanip>
#include <set>
#include <map>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <numeric>
#include <cstdio>
#include <cmath>
#include <list>
#include <bitset>
#include <cassert>
using namespace std;
 
#define int long long
struct Q{
    int l, r, idx;
};
 
bool cmp(const Q &a, const Q &b){
    return a.r < b.r;
}
 
const int MX = 1e5 + 5;
int arr[MX];
int pos[MX];
int bit[MX];
Q q[MX];
 
int n, m, d;
 
void update(int idx, int delta = 1LL){
    while (idx <= n){
        bit[idx] += delta;
        idx += (idx & (-idx));
    }
}
 
int query(int idx){
    int ans = 0;
    while (idx > 0){
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}
 
 
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n >> m >> d;
 
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        arr[i] = x;
        pos[x] = i;
    }
    for (int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        q[i].l = l;
        q[i].r = r;
        q[i].idx = i;
    }
 
    sort(q, q + m, cmp);
    int ans[m];
    for (int i = 1, j = 0; i <= n && j < m; i++){
        for (int k = max(1ll, arr[i] - d); k <= min(n, arr[i] + d); k++){
            if (pos[k] <= i){
                update(pos[k]);
            }
        }
        while (j < m && q[j].r == i){
            ans[q[j].idx] = query(q[j].r) - query(q[j].l - 1);
            j++;
        }
    }
    for (int i = 0; i < m; i++){
        cout << ans[i] << "\n";
    }
 
 
    return 0;
}
