/*
=====================
|  ID:   mshafqats  |
|  LANG: C++        |
=====================
Mohammad Shafqat Siddiqui
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
ll bit[2][300100];
inline void init(){
    memset(bit, 0, sizeof(bit));
}
void update(int val, int x, int idx){
    while(x <= 3e5){
        bit[idx][x] += val;
        x += (x&(-x));
    }
}
 
ll query(int x, int idx){
    ll ret = 0;
    while(x){
        ret += bit[idx][x];
        x -= (x&(-x));
    }
    return ret;
}
struct node{
    int x, i, j;
    node(){}
    node(int x, int i, int j){
        this->x = x;
        this->i = i;    
        this->j = j;
    }
};
 
bool compare(node a, node b){
    return a.x < b.x;
}
int a[3][300100]={0};
int main(){
    int t;
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>t;
    while(t--){
        init();
        map<ll, int> m;
        int n, k; cin>>n>>k;
        
        vector<node> v;
        for(int i=1; i<=n; i++){
            int temp;cin>>temp;
            v.push_back(node(temp, i, 0));
            v.push_back(node(temp-k, i, 1));
            v.push_back(node(temp+k, i, 2));    
        }
        sort(v.begin(), v.end(), compare);
        int cnt = 0;
        for(int i=0; i<v.size(); i++){
            if(!i or v[i].x != v[i-1].x)cnt++;
            a[v[i].j][v[i].i] = cnt;
        }   
 
        ll ans = 0;
        for(int i=1; i<=n; i++){
            ll sum = 0;
            sum += query(a[1][i], 0);
            sum += query(3e5-a[2][i]+1, 1);
            update(i, a[0][i], 0);
            update(i, 3e5-a[0][i]+1, 1);
            ans += (sum*(n-i+1));
        }
        cout<<ans<<endl;
    }
    return 0;
}
