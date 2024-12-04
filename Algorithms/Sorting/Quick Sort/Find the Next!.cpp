/*
=====================
|  ID:   mshafqats  |
|  LANG: C++        |
=====================
Mohammad Shafqat Siddiqui
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fst first
#define snd second
const int maxi=1e9+1;

int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   int n,q;cin>>n>>q;
   vector<int>a(n);
   for(int i=0;i<n;i++){
      cin>>a[i];
   }
   sort(a.begin(),a.end());
   a.pb(maxi);
   vector<pii>b;
   for(int i=0;i<=n-1;i++){
      if(a[i]!=a[i+1]){
         b.pb({a[i],0});
      }
   }
   int aux=0;
   for(int i=b.size()-1;i>=1;i--){
      if(b[i].fst==b[i-1].fst+1){
         aux++;
         b[i-1].snd=aux;
      }else{
         aux=0;
      }
   }
   while(q--){
      int x;cin>>x;
      int l=0,r=b.size();
      int pos=-1;
      while(l<=r){
         int mid=(l+r)/2;
         if(x+1==b[mid].fst){
            pos=mid;break;
         }else if(x+1>b[mid].fst){
            l=mid+1;
         }else{
            r=mid-1;
         }
      }
      if(pos==-1){
         cout<<x+1<<"\n";
      }else{
         cout<<x+1+b[pos].snd+1<<"\n";
      }
   }
   return 0;
}
