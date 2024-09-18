/*
=====================
|  ID:   mshafqats  |
|  LANG: C++        |
=====================
Mohammad Shafqat Siddiqui
*/

#include<bits/stdc++.h>
#define ll long long int
#define fastScan ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
typedef pair <ll, ll> pll;
 
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
 
const ll N = 100001;
 
ll In[N];
ll Out[N];
ll t = 0;
ll Euler[N << 3];
ll Levels[N << 3];
 
class SparseTable {
 
  public:
 
    ll * l2, * M[30];
 
    ll getMinIndex(ll i, ll j) {
      ll k = l2[j - i + 1];
      if(A[M[k][i]] <= A[M[k][j - (1 << k) + 1]])
        return M[k][i];
      return M[k][j - (1 << k) + 1];
    }
 
    ll getMinVal(ll i, ll j) {
      return A[getMinIndex(i, j)];
    }
 
    SparseTable(ll t) {
      A.assign(t, 0);
      l2 = new ll[t * 2];
      for(ll i = 0; i < t; i++) {
        A[i] = Levels[i];
      }
      l2[1] = 0; l2[2] = 1;
      for(ll i = 0; i < 30; i++) {
        M[i] = new ll[t];
      }
      for(ll i = 3; i < 2 * t; i++) {
        if((i & (i - 1)) == 0) l2[i] = l2[i - 1] + 1;
        else l2[i] = l2[i - 1];
      }
      n = A.size();
      ll i, j;
      for (i = 0; i < n; i++) M[0][i] = i;
      for (j = 1; 1 << j <= n; j++) {
        for (i = 0; i + (1 << j) - 1 < n; i++) {
          if (A[M[j - 1][i]] < A[M[j - 1][i + (1 << (j - 1))]])
            M[j][i] = M[j - 1][i];
          else
            M[j][i] = M[j - 1][i + (1 << (j - 1))];
        }
      }
    }
 
  private:
 
    ll n;
    vector<ll> A;
};
 
 
struct st {
 
  ll sum;
  ll pref;
  ll suff;
  ll ans;
 
  st(ll sum, ll pref, ll suff, ll ans) : sum(sum), pref(pref), suff(suff), ans(ans) {
 
  }
 
  static st neg(st b) {
    swap(b.pref, b.suff);
    return b;
  }
 
  st() {
    sum = pref = suff = ans = LONG_MIN;
  } 
 
  st(ll a) {
    sum = pref = suff = ans = a;
  }
 
  st operator + (st rhs) {
    if(ans == LONG_MIN) return rhs;
    if(rhs.ans == LONG_MIN) return * this;
    st res;
    res.sum = sum + rhs.sum;
    res.pref = max(pref, sum + rhs.pref);
    res.suff = max(rhs.suff, rhs.sum + suff);
    res.ans = max(ans, rhs.ans);
    res.ans = max(res.ans, suff + rhs.pref);
    return res;
  }
 
  st operator - (st rhs) {
    return (*this) + neg(rhs);
  }
 
};
 
st nodeData[N];
ll L[N];
bool vis[N];
st part[N][20];
vector <ll> adj[N];
 
void addEdge(ll u, ll v) {
  adj[u].emplace_back(v);
  adj[v].emplace_back(u);
}
 
 
ll sz[N];
 
void dfs(ll s, ll p = -1) {
  sz[s] = 1;
  for(auto c : adj[s]) {
    if(c == p || vis[c]) continue;
    dfs(c, s);
    sz[s] += sz[c];
  }  
}
 
void dfsData(ll s, ll f, ll p = -1, st cont = st()) {
  part[s][L[s] - L[f]] = cont;
  for(auto c : adj[s]) {
    if(c != p && (!vis[c])) {
      dfsData(c, f, s, cont + nodeData[c]);
    }
  }
}
 
ll findCentroid(ll s) {
  dfs(s, -1);
  ll total = sz[s];
  ll p = -1;
  for(ll big = -1; ;big = -1) {
    for(auto c : adj[s]) {
      if(c != p && (!vis[c])) {
        if(big == -1 || sz[big] < sz[c]) big = c;
      }
    }
    if(big == -1 || sz[big] * 2 <= total) break;
    else { p = s; s = big; }
  }
  return s;
}
 
ll createTree(ll s, ll d = 0) {
  ll ce = findCentroid(s);
  Euler[t] = ce; Levels[t] = d; In[ce] = t++;
  vis[ce] = true;
  L[ce] = d;
  for(auto ch : adj[ce]) {
    if(!vis[ch]) {
      ll x = createTree(ch, d + 1);
      Euler[t] = ce; Levels[t] = d; Out[ce] = t++;
    }
  }
  dfsData(ce, ce, -1, st());
  vis[ce] = false;
  Euler[t] = ce; Levels[t] = d; Out[ce] = t++;
  return ce;
}
 
SparseTable * S;
 
ll lca(ll u, ll v) {
  ll mn = min(In[u], In[v]);
  ll mx = max(Out[u], Out[v]);
  return Euler[S->getMinIndex(min(In[u], In[v]), max(Out[u], Out[v]))];
}
 
//works in O(1)
st query(ll u, ll v) {
  ll _lca = lca(u, v);
  return st::neg(part[u][L[u] - L[_lca]]) + nodeData[_lca] + part[v][L[v] - L[_lca]];
}
 
 
int main() {
 
 
    srand(time(NULL));
 
    ll n;
    scanf("%lld", &n);
 
    for(ll i = 0; i < n - 1; i++) {
      ll u, v;
      scanf("%lld%lld", &u, &v);
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }
 
    for(ll i = 1; i <= n; i++) {
      ll vall;
      scanf("%lld", &vall);
      nodeData[i] = (st) {vall, vall, vall, vall};
    }
 
    createTree(1);
    S = new SparseTable(t);
 
    ll q;
    scanf("%lld", &q);
 
    for(ll i = 0; i < q; i++) {
      ll a, b;
      scanf("%lld%lld", &a, &b);
      st res = query(a, b);
      printf("%lld\n", res.ans);
    }
 
    return 0;
}
