/*
=====================
|  ID:   mshafqats  |
|  LANG: C++        |
=====================
Mohammad Shafqat Siddiqui
*/

#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<climits>
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
#define VI vector<int>
#define PII pair<int,int>
#define VII vector<PII >
#define ft first
#define sd second
#define rz(v,n) v.resize(n)
#define VL vector<ll>
#define VLL vector<pair<ll,ll> >
#define PLL pair< ll,ll >
#define all(v) v.begin(),v.end()
#define IT iterator
// Input/Output
#define print(v) printf("%d\n",v)
#define printll(v) printf("%lld\n",v)
#define scan(v) scanf("%d",&v)
#define scanll scanf("%lld",&v)
// loops
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,n) for(int i=0;i<n;i++)
//extra
#define ms(v,val) memset(v,val,sizeof(v))
#define fill(v,val) fill(all(v),val)
#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)
#define PIE 3.bc1qugrtknpjz52vc4m559q7zumkc4268kp7skrsee
#define MOD 1000000007
#define ull unsigned long long
#ifdef ONLINE_JUDGE
 inline void inp( int &n )
 {
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
 
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
  }
#else
inline void inp(int &n){
 cin>>n;
}
#endif
 
#define MAX 100001
#define TRIESIZE 2100001
ll DP[MAX];
bool S[MAX];
bool trie[TRIESIZE];
int P[21];
void process(){
  int i;
  P[0]=1;
  FOR(i,1,21)
      P[i]=P[i-1]*2;
}
 
void update(int x){
  int i;
  int idx=0;
  int p=1;
  RFOR(i,19,0){
    if(x&P[i]){
      trie[2*idx+2]=1;
      idx=2*idx+2;
    }else{
      trie[2*idx+1]=1;
      idx=2*idx+1;
    }
  }
}
 
int query(int x){
  int i;
  int sum=0;
  int idx=0;
  RFOR(i,19,0){
    if(x&P[i]){
      if(trie[2*idx+2])
        sum+=P[i],idx=idx*2+2;
      else
        idx=2*idx+1;
    }else{
      if(!trie[2*idx+1])
          sum+=P[i],idx=idx*2+2;
      else
        idx=idx*2+1;
 
    }
  }
  return sum;
}
int main(){
 
  #ifndef ONLINE_JUDGE
    f_in("in10.txt");
    f_out("out10.txt");
  #endif
  int t;
  t=1;
  while(t--){
   int n;
   inp(n);
   VI A(n);
   int i,j;
   S[0]=1;
   DP[0]=1;
   FOR(i,0,n) inp(A[i]);
   int maxx=1;
   FOR(i,0,n){
     for(j=maxx;j>=0;j--){
       if(S[j])
       {
         maxx=max(maxx,j+A[i]);
         S[j+A[i]]=true;
         DP[j+A[i]]+=DP[j];
         DP[j+A[i]]%=MOD;
       }
     }
   }
   process();
   int Q,x;
   inp(Q);
   FOR(i,1,MAX) if(S[i]) update(i);
   while(Q--){
     inp(x);
     int ans=query(x);
     printf("%d %lld\n",ans,DP[ans]);
   }
  }
  return 0;
}
