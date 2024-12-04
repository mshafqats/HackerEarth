/*
=====================
|  ID: mshafqats    |
|  LANG: C++        |
=====================
Mohammad Shafqat Siddiqui
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> pow2(31, 1);
    
void dfs(int node, int father, const vector<vector<int>>& aux, const vector<int>& A, multiset<int>& S, const vector<vector<pair<int, int>>>& values, vector<int>& res){

    S.insert(A[node]);
    for(auto adj : aux[node])
        if(adj != father){
            dfs(adj, node, aux, A, S, values, res);
        }

for(auto query : values[node]){
    int sol = 31, nr;
    auto it = S.lower_bound(query.first);
    auto itt = --S.lower_bound(query.first);
    if(it == S.end()){
        --it;
        --itt;
    }
    if(it != S.end()){
        nr = *it;
        for(int j = 30; j >= 0; --j){
            if((pow2[j] & nr && !(pow2[j] & query.first)) || (pow2[j] & query.first && !(pow2[j] & nr)))
                break;
                sol = max(sol, 62 - j);
                }
    }
    if(itt != S.end()){
        nr = *itt;
        for(int j = 30; j >= 0; --j){
            if((pow2[j] & nr && !(pow2[j] & query.first)) || (pow2[j] & query.first && !(pow2[j] & nr)))
                break;
                sol = max(sol, 62 - j);
                }
    }
    res[query.second] = sol;  
}
    auto it = S.find(A[node]);
    S.erase(it);
}
    
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    for(int i = 1; i <= 30; ++i)
        pow2[i] = pow2[i - 1] * 2;
    
    int T; cin >> T;
    for(; T > 0; --T){
        int N; cin >> N;
        vector<int> A(N);
        multiset<int> S;
        vector<bool> used(N, false);
        for(int i = 0; i < N; ++i)
            cin >> A[i];
    
        vector<vector<int>> aux(N, vector<int>{});
        for(int i = 0; i < N - 1; ++i){
            int x, y; cin >> x >> y; --x; --y;
            aux[x].push_back(y);
            aux[y].push_back(x);
        }
    
        int Q; cin >> Q;
        vector<vector<pair<int, int>>> values(N, vector<pair<int, int>>{});
        vector<int> res(Q);
        for(int i = 0, v, x; i < Q; ++i){
            cin >> v >> x;
            --x;
            values[x].push_back(make_pair(v, i));
        }

        dfs(0, -1, aux, A, S, values, res);
        
        for(auto r : res)
            cout << r << " ";
        cout << "\n";
    }
    return 0;
}
