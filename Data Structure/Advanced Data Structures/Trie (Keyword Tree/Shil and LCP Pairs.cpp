/*
=====================
|  ID: mshafqats    |
|  LANG: C++        |
=====================
Mohammad Shafqat Siddiqui
*/

#include <bits/stdc++.h>
using namespace std;
 
typedef int  ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
#define pb push_back
#define MAXN 1000005
const ll N=31;
#define INF (ll)1e18
#define mod 1000000007
//#define mod 998244353
#define fi first
#define se second
#define mkp make_pair
#define sze(x) ((ll)x.size())
#define all(v) v.begin(),v.end()
#define endl '\n'
ll cc=0,cc1=0;
ll timer;
 
 
void boost()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
 
long long dp[MAXN];
 
 
struct node
{
    ll f=0;
    ll child[26]={0};
    
}nil;
 
vector<node> trie(1,nil);
 
void insert(string s)
{
    ll cur=0,i,z,l;
    ++trie[cur].f;
    
    for(auto x : s)
    {
        l=x-'a';
        
        z=trie[cur].child[l];
        
        if(z==0)
        {
            z=trie.size();
            trie[cur].child[l]=z;
            trie.pb(nil);
        }
        
        cur=z;
        ++trie[cur].f;
        
    }
}
 
void query(string s)
{
    ll cur=0,i,z,ans=0,l,r;
    
    for(i=0;i<sze(s);i++)
    {
        l=s[i]-'a';
        
        z=trie[cur].child[l];
        
        if(z==0)
        {
            dp[i]+=trie[cur].f;
            break;
        }
        
        else
        {
        r=trie[z].f;
        dp[i]+=(trie[cur].f-r);
        }
        
        cur=z;
        
        if(i==(sze(s)-1))
        {
            dp[i+1]+=trie[cur].f;
        }
    }
    
}
 
 
int main()
{
    boost();
 
    ll i,t,q,l,r,ans,mid,c,z,j,k,v;
    ll h,n,m,u,mm,w,mx,x,y,l1,r1,d=0,mask;
    ld f;
    
        
    cin>>n;
    string s[n];
    
    r=0;
    
    for(i=0;i<n;i++)
    {
        cin>>s[i];
        r=max(r,sze(s[i]));
    }
    
    
    
    insert(s[0]);
    
    for(i=1;i<n;i++)
    {
        query(s[i]);
        insert(s[i]);
    }
    
    for(i=0;i<=r;i++)
    {
        cout<<dp[i]<<" ";
    }
    
    cout<<endl;
    
    
return 0;
}
