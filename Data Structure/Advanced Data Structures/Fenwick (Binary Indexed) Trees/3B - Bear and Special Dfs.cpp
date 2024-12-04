/*
=====================
|  ID:   mshafqats  |
|  LANG: C++        |
=====================
Mohammad Shafqat Siddiqui
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fre     freopen("0.in","r",stdin);freopen("0.out","w",stdout)
#define abs(x) ((x)>0?(x):-(x))
#define MOD 1000000007
#define LL signed long long int
#define pii pair<int,int>
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x)
#define rep(i,from,to) for(int i=(from);i <= (to); ++i)
vector<int> G[2*100000+5];
int L[100000+5],R[100000+5], A[100000+5];
LL tree[5*100000+5];
LL lazy[5*100000+5];
int T = 0;
void dfs(int v,int p){
    L[v] = ++T;
    for(int i=0;i<G[v].size();++i){
        int u = G[v][i];
        if(u==p)
            continue;
        dfs(u,v);
    }
    R[v] = T;
}
 
LL pow(LL base, LL exponent,LL modulus)
{
    LL result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}
 
void build(int i,int si,int sj){
    if(si==sj){
        tree[i] = 1;
        lazy[i] = 1;
    }
    else{
        int mid = (si+sj)/2;
        build(2*i,si,mid);
        build(2*i+1,mid+1,sj);
        tree[i] = tree[2*i]+tree[2*i+1];
        lazy[i] = 1;
    }
}
void update(int i,int si,int sj,int qi,int qj,int x){
    if(si==qi and sj==qj){
        tree[i] = tree[i] * x % MOD;
        lazy[i] = lazy[i] * x % MOD;
    }
    else{
        int mid = (si+sj)/2;
        if(qj<=mid)
            update(2*i,si,mid,qi,qj,x);
        else if(mid+1<=qi)
            update(2*i+1,mid+1,sj,qi,qj,x);
        else
            update(2*i,si,mid,qi,mid,x),
            update(2*i+1,mid+1,sj,mid+1,qj,x);
        tree[i] = (tree[2*i] + tree[2*i+1]) * lazy[i] % MOD;
    }
}
LL query(int i,int si,int sj,int qi,int qj){
    if(qi==si and qj==sj){
        return tree[i];
    }
    else{
        int mid = (si+sj)/2;
        LL x = 0;
        if(qj<=mid)
            x = query(2*i,si,mid,qi,qj);
        else if(mid+1<=qi)
            x = query(2*i+1,mid+1,sj,qi,qj);
        else
            x = query(2*i,si,mid,qi,mid) + query(2*i+1,mid+1,sj,mid+1,qj);
        return x * lazy[i] % MOD;
    }
}
int N;
void update(int i,int j,int x){
    if(i<=j){
        update(1,1,N,i,j,x);
    }
}
 
int main(){
    //fre;
    int Q,a,b,c,x,v;
    cin>>N>>Q;
    rep(i,1,N-1){
        scan(a);
        scan(b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1,0);
    build(1,1,N);
    rep(i,1,N)scan(A[i]),update(L[i]+1,R[i],A[i]);
    while(Q--){
        scan(c);
        if(c==1){
            //update
            scan(v);
            scan(x);
            update(L[v]+1,R[v],pow(A[v],MOD-2,MOD));
            A[v] = x;
            update(L[v]+1,R[v],A[v]);
        }
        else{
            //query
            scan(v);
            printll(query(1,1,N,L[v],R[v]));
        }
    }
}
