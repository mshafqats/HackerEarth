/*
=====================
|  ID:   mshafqats  |
|  LANG: C++        |
=====================
Mohammad Shafqat Siddiqui
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 1e16
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define pii pair< int,int >
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
ll tree[100001];
    void update(long long n,long long idx,long long val)
    {
        while(idx<=n)
        {
            tree[idx] += val;
            idx +=(idx&(-idx));
        }
    }
long long sum(long long idx)
    {
        long long ans=0;
        while(idx>0)
        {
            ans += tree[idx];
            idx -= (idx&(-idx));
        }
        return ans;
    }
int main()
{
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast;
   ll n;
   cin>>n;
   map<ll,ll> mp;
   ll a[n+1];
   for(ll i=1;i<=n;i++)
   {
       cin>>a[i];
       mp[a[i]];
   }
   ll m1=-1,m2=1,l=-1,r=-1;
    for(ll i=1;i<=n;i++){
        ll d=a[i]-i;
        if(d>m1){
            m1=d,l=i;
        }
    }
    for(ll i=1;i<=n;i++){
        ll d=a[i]-i;
        if(d<m2){
            m2=d,r=i;
        }
    }
    swap(a[l],a[r]);
   ll cnt=1;
   for(auto &it: mp)
   {
       it.second=cnt++;
   }
   for(ll i=1;i<=n;i++)
   {
       a[i]=mp[a[i]];
   }
   ll inv=0;
   for(ll i=1;i<=n;i++)
   {
       inv += (sum(n)-sum(a[i]));
       update(n,a[i],1);
   }
   cout<<inv<<"\n";
  return 0;
}
