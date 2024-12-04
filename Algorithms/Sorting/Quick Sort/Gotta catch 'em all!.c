/*
=====================
|  ID:   mshafqats  |
|  LANG: C          |
=====================
Mohammad Shafqat Siddiqui
*/

#include <stdio.h>
#include <stdlib.h>
 
int cmpfunc(const void *a, const void *b) {
  return *(int*)b - *(int*)a;
}
 
int solve(int *arrr, int n) {
  int sum = 0;
 
  qsort(arrr, n, sizeof(int), cmpfunc);
 
  sum = arrr[0];
 
  for (int j = 1; j< n; j++) {
    if (sum < (arrr[j] + j)) sum = arrr[j] + j;
  }
 
  return sum + 2;
}
 
int main() {
  int n;
 
  scanf("%d", &n);
 
  int arrr[n];
 
  for (int j = 0; j < n; j++) {
    scanf("%d", &arrr[j]);
  }
 
  printf("%d\n", solve(arrr, n));
 
  return 0;
}
