/*
=====================
|  ID:   mshafqats  |
|  LANG: C++        |
=====================
Mohammad Shafqat Siddiqui
*/

#include <cstdio>
#include <iostream>
#include <malloc.h>
 
template<typename T>
void swap(T &x, T &y) {
	T temp = x;
	x = y;
	y = temp;
}
 
typedef struct pair {
	int f, s;
	int i;
} pair;
 
template <typename T>
bool cmp(T &x, T &y) {
	if(x.f < y.f)
		return true;
	if(x.f == y.f)
		return x.s <= y.s;
	return false;
}
 
template <typename T>
int part(T *v, int l, int r) {
	int pi = (l + r) / 2;
 
	// bool g1 = cmp(v[l], v[m]);
	// bool g2 = cmp(v[m], v[r]);
	// bool g3 = cmp(v[l], v[r]);
 
	// if(g1 && g2) pi = m;
	// if(!g1 && !g2) pi = m;
	// if(g1 && !g2) {
	// 	if(g3) pi = r;
	// 	else pi = l;
	// } else {
	// 	if(g3) pi = l;
	// 	else pi = r;
	// }
 
	swap(v[pi], v[r]);
	pi = r;
 
	int i = l - 1;
	for(int j = l; j < r; j++) {
		if(cmp(v[j], v[pi])) {
			i++;
			swap(v[i], v[j]);
		}
	}
	swap(v[i + 1], v[pi]);
	return i + 1;
}
 
template <typename T>
void mysort(T *v, int l, int r) {
	if(l >= r)
		return;
	int p = part(v, l, r);
	mysort(v, l, p - 1);
	mysort(v, p + 1, r);
}
 
int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	scanf("%d", &n);
	pair *v = (pair *) malloc(n * sizeof(pair));
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &v[i].f, &v[i].s);
		v[i].i = i;
	}
	mysort(v, 0, n - 1);
 
	// for(int i = 0; i < n; i++) {
	// 	printf("%d %d\n", v[i].f, v[i].s);
	// }
 
	int ans = 0, rev = 0, i = 0;
	int *op = (int *) malloc(n * sizeof(int));
	while(i < n) {
		if(rev) {
			int en = i;
			while(en < n and v[en].f == v[i].f) {
				en++;
			}
			int here = en;
			en--;
			while(en >= i) {
				op[v[en].i] = ans;
				ans++;
				en--;
			}
			i = here - 1;
		} else {
			int en = i;
			while(en < n and v[en].f == v[i].f) {
				op[v[en].i] = ans;
				ans++;
				en++;
			}
			i = en - 1;  
		}
		i++;
		rev ^= 1;
	}
	for(int i = 0; i < n; i++) {
		printf("%d\n", op[i]);
	}
	return 0;
}
