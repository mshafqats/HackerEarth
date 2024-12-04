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
typedef long double ld;
typedef double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<db, db> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<pdd> vdd;
#define f first
#define s second
const int MN=1e5+1;
int n, q, ind[MN], bit[MN], b[MN], ans[MN];
vector<array<int, 5>> v; 
 
void update(int i, int val) {
    for(i++; i<=n;) bit[i]+=val, i+=i&(-i);
}
int query(int i) {
    int s=0;
    for(i++; i>0;) s+=bit[i], i-=i&(-i);
    return s;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    if(fopen("input.txt", "r"))
        freopen("input.txt", "r", stdin),
        freopen("output.txt", "w", stdout);
    cin>>n;
    for(int i=0, a; i<n; i++) {
        cin>>a;
        ind[a]=i;
    } 
    for(int i=0; i<n; i++) cin>>b[i];
    cin>>q;
    for(int i=0; i<q; i++) {
        int l1, r1, l2, r2;
        cin>>l1>>r1>>l2>>r2;
        l1--, r1--, l2--, r2--;
        ans[i]=r1-l1+1;
        v.push_back({l2, l1, r1, 1, i});
        v.push_back({r2, l1, r1, -1, i});
    }
    sort(v.begin(), v.end());
    for(int i=0, j=0, k=0; i<n; i++) {
        for(k=j; k<(int)v.size(); k++) {
            auto cur=v[k];
            if(cur[0]!=i) break;
            if(cur[3]==1) ans[cur[4]]+=query(cur[2])-query(cur[1]-1);
        }
        update(ind[b[i]], 1);
        for(k=j; k<(int)v.size(); k++) {
            auto cur=v[k];
            if(cur[0]!=i) break;
            if(cur[3]==-1) {
                ans[cur[4]]-=query(cur[2])-query(cur[1]-1);
            }
        }
        j=k;
    }
    for(int i=0; i<q; i++) {
        cout<<ans[i]<<"\n";
    }
}
