/*
=====================
|  ID:   mshafqats  |
|  LANG: C++        |
=====================
Mohammad Shafqat Siddiqui
*/

#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <cstring>
#include <functional>
#include <climits>
#include <list>
#include <ctime>
#include <complex>
    
#define F1(x,y,z) for(int x=y;x<z;x++)
#define F2(x,y,z) for(int x=y;x<=z;x++)
#define F3(x,y,z) for(int x=y;x>z;x--)
#define F4(x,y,z) for(int x=y;x>=z;x--)
#define pb push_back
#define LL long long
#define co complex<double>
    
#define MAX 100005
#define AMAX 1500
#define MOD 1000000007
    
#define f(c,d) ((1<<(c))*(d))
    
using namespace std;
    
int n,m,ta,tb,nx[MAX*15],i[MAX*15],at[MAX*5],att[MAX*5],nxx[MAX*15],ia[MAX*15],ib[MAX*15],si,x[20][MAX*5],par[MAX*5],anc[MAX*5],q[MAX*5][3],la[MAX*5];
bool v[MAX*5];
    
int find(int a){
    if(par[a]==a)return a;
    return par[a]=find(par[a]);
}
    
void dfs(int a,int b){
    la[a]=b;
    at[a]=si++;
    par[a]=a;
    anc[a]=a;
    for(int c=nx[a];c;c=nx[c])if(i[c]!=b){
        dfs(i[c],a);
        par[find(i[c])]=find(a);
        anc[par[a]]=a;
    }
    att[a]=si;
    v[a]=1;
    for(int c=nxx[a];c;c=nxx[c])if(v[ia[c]])q[ib[c]][2]=anc[find(ia[c])];
}
    
int f1(int a,int b,int c,int d){
    if(f(c,d)==a&&f(c,d+1)==b)return x[c][d];
    c--;
    d=(d<<1)|1;
    if(b<=f(c,d))return f1(a,b,c,d^1);
    if(a>=f(c,d))return f1(a,b,c,d);
    return f1(a,f(c,d),c,d^1)+f1(f(c,d),b,c,d);
}
    
int main(){
    scanf("%d%d",&n,&m);
    si=n+1;
    F1(a,1,n){
        scanf("%d%d",&ta,&tb);
        i[si]=tb;
        nx[si]=nx[ta];
        nx[ta]=si++;
        i[si]=ta;
        nx[si]=nx[tb];
        nx[tb]=si++;
    }
    si=n+1;	
    F1(a,0,m){
        scanf("%d",&ta);
        if(ta&1){
            scanf("%d%d",&q[a][0],&q[a][1]);	
            ia[si]=q[a][1];
            ib[si]=a;
            nxx[si]=nxx[q[a][0]];
            nxx[q[a][0]]=si++;	
            ia[si]=q[a][0];
            ib[si]=a;
            nxx[si]=nxx[q[a][1]];
            nxx[q[a][1]]=si++;
        }else scanf("%d",&q[a][1]);
    }
    si=0;
    dfs(1,0);
    F1(a,0,m){
        if(q[a][0]){
            ta=at[q[a][0]];
            F1(b,0,20){
                x[b][ta]++;
                ta>>=1;
            }
            ta=at[q[a][1]];
            F1(b,0,20){
                x[b][ta]++;
                ta>>=1;
            }
            ta=at[q[a][2]];
            F1(b,0,20){
                x[b][ta]--;
                ta>>=1;
            }
            if(la[q[a][2]]){
                ta=at[la[q[a][2]]];
                F1(b,0,20){
                    x[b][ta]--;
                    ta>>=1;
                }
            }
        }else printf("%d\n",f1(at[q[a][1]],att[q[a][1]],19,0));
    }
    //system("pause");
    return 0;
}