/*
=====================
|  ID: mshafqats    |
|  LANG: C++        |
=====================
Mohammad Shafqat Siddiqui
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
const int N = 1e5+5;
const int bit = 20;
vector< pair<int, int> > adj[N];
int t, n, u, v, w, sz = 0;
int lca[N][bit+1] = {};
int s[N], f[N], cc = -1;
int arr[N];
 
struct node {
	int ch[2], cnt;
	node() {
		cnt = ch[0] = ch[1] = 0;
	}
} st[N*50];
 
int add(int prev, int x) {
	int curr = ++sz;
	int tmp = curr; 
	for( int i = bit; i >= 0; i-- ) {
		bool j = (x>>i)&1;
		if( !st[curr].ch[j] ) {
			st[curr].ch[j] = ++sz;
		}
		st[curr].ch[1-j] = st[prev].ch[1-j];
		prev = st[prev].ch[j];
		curr = st[curr].ch[j];
		st[curr].cnt = st[prev].cnt+1;
	}
	return tmp;
}
 
void dfs(int i, int p, int val) {
	s[i] = ++cc;
	if(p != -1) {
		arr[s[i]] = add(arr[s[p]], val);
		lca[i][0] = p;
		for( int j = 1; j <= bit; j++ ) {
			lca[i][j] = lca[lca[i][j-1]][j-1];
		}
	}
	for( int j = 0; j < adj[i].size(); j++ ) {
		int d = adj[i][j].first;
		if( d != p ) {
			dfs(d, i, adj[i][j].second);
		}
	}
	f[i] = cc;
}
 
bool isLca(int a, int b) { return s[a] <= s[b] && f[a] >= f[b]; }
 
int getLca(int a, int b) {
	if( isLca(a, b) ) {
		return a;
	}
	if( isLca(b, a) ) {
		return b;
	}
	for( int i = bit; i >= 0; i-- ) {
		if( !isLca(lca[a][i], b) ) { a = lca[a][i];
		}
	}
	return lca[a][0];
}
 
int get(int l, int r, int x) {
	if( l == r ) {
		return 0;
	}
	int res = 0;
	for( int i = bit; i >= 0; i-- ) {
		int j = (x>>i)&1;
		if( !st[r].ch[1-j] || st[st[r].ch[1-j]].cnt == st[st[l].ch[1-j]].cnt ) {
			j ^= 1;
		}
		else {
			res |= (1<<i);
		}
		l = st[l].ch[1-j];
		r = st[r].ch[1-j];
	}
	return res;
}
 
int main() {
	arr[0] = 0;
	
	scanf("%d%d", &n, &t);
	for( int i = 0; i < n-1; i++ ) {
		scanf("%d%d%d", &u, &v, &w);
		u--, v--;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	
	dfs(0, -1, 0);
	
	while(t--) {
		scanf("%d%d%dd", &u, &v, &w);
		u--, v--;
		int l = getLca(u, v);
		int res = max(get(arr[s[l]], arr[s[v]], w), get(arr[s[l]], arr[s[u]], w));
		printf("%d\n", res);
	}
	return 0;
}
