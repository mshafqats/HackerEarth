/*
=====================
|  ID:   mshafqats  |
|  LANG: C          |
=====================
Mohammad Shafqat Siddiqui
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define N  100000
 
 
 
void update(int *tt, int i, int n, int x) {
  while (i < n) {
    tt[i] += x;
    i |= (i + 1);
  }
}
 
int query(int *tt, int i) {
  int sum = 0;
 
  while (i >= 0) {
    sum += tt[i];
    i &= (i + 1);
    i--;
  }
  return sum;
}
 
struct element {
  int a, i;
} ee[N];
 
int compare(const void *a, const void *b) {
  struct element *pa = (struct element *) a;
  struct element *pb = (struct element *) b;
 
  return pa->a != pb->a ? pa->a - pb->a : pa->i - pb->i;
}
 
int main() {
  int t;
 
  scanf("%d", &t);
  while (t-- > 0) {
    int n, i, j, cnt;
    static int tt[N + 1];
 
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%d", &ee[i].a);
      ee[i].i = i + 1;
    }
    qsort(ee, n, sizeof *ee, compare);
    cnt = 0;
    memset(tt, 0, (N + 1) * sizeof *tt);
    for (i = 0; i < n - 1; ) {
      int used = query(tt, ee[i].i);
      int x = (ee[i].a - cnt) / (ee[i].i - used) + 1;
 
      j = i;
      while (j < n && ee[j].a - cnt < x * (ee[i].i - used))
        update(tt, ee[j++].i, n + 1, 1);
      cnt += x * (ee[i].i - used);
      i = j;
    }
    printf("%s\n", i == n - 1 ? "Ladia" : "Kushagra");
  }
  return 0;
}
