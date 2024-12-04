/*
=====================
|  ID:   mshafqats  |
|  LANG: C++        |
=====================
Mohammad Shafqat Siddiqui
*/

#include "bits/stdc++.h"
using namespace std;
struct ${$(){ios_base::sync_with_stdio(0);cin.tie(0);}}$;
const int N = 150000 + 5;
const int MX = 20000 + 5;
int x[N], y[N];
int x_left[N], x_right[N];
int y_down[N], y_up[N];
 
enum BorderState {
   OPEN,
   POINT,
   CLOSE,
};
 
struct segmentBorder {
   BorderState state;
   int y_d, y_u, x, id;
   bool operator <(const segmentBorder &s) {
      return x < s.x || (x == s.x && state < s.state);
   }
};
 
 
struct BIT {
   int n;
   long long LS, SS;
  
   BIT operator +(const BIT& a) const {
      return {n + a.n, LS + a.LS, SS + a.SS};
   }
 
   BIT operator -(const BIT& a) const {
      return {n - a.n, LS - a.LS, SS - a.SS};
   }
} B[MX];
 
BIT ans[2][N];
 
void update(int idx, int val) {
   long long val2 = val * 1LL * val;
   while(idx < MX) {
      B[idx].n += 1;
      B[idx].LS += val;
      B[idx].SS += val2;
      idx += idx & -idx;
   }
}
 
BIT get(int idx) {
   BIT ret = {0, 0LL, 0LL};
   while(idx > 0) {
      ret.n += B[idx].n;
      ret.LS += B[idx].LS;
      ret.SS += B[idx].SS;
      idx -= idx & -idx;
   } 
   return ret;
}
 
BIT get(int l, int r) {
   return get(r) - get(l - 1);
}
 
void go(int p, int q, int turn) {
 
   vector <segmentBorder> borders;
   for(int i = 0; i < p; i++) {
      borders.push_back({POINT, y[i], -1, x[i], -1});
   }
 
   for(int i = 0; i < q; i++) {
      segmentBorder left_border({OPEN, y_down[i], y_up[i], x_left[i], i});
      segmentBorder right_border({CLOSE, y_down[i], y_up[i], x_right[i], i});
      
      borders.push_back(left_border);
      borders.push_back(right_border);
   }
 
   sort(borders.begin(), borders.end());
 
   for(int i = 0; i < borders.size(); i++) {
      if(borders[i].state == POINT) {
         update(borders[i].y_d, borders[i].x);
      } else if(borders[i].state == OPEN) {
         BIT val = get(borders[i].y_d, borders[i].y_u);
         ans[turn][borders[i].id] = ans[turn][borders[i].id] - val;
      } else if(borders[i].state == CLOSE) {
         BIT val = get(borders[i].y_d, borders[i].y_u);
         ans[turn][borders[i].id] = ans[turn][borders[i].id] + val;
      } 
   }
}
 
long long magic(BIT t) {
   unsigned long long int ret = t.n * 1ULL * t.SS - t.LS * 1ULL * t.LS;
   ret = ret * 3ULL;
   ret += t.LS;
   return ret;
}
 
int main() {
   int p, q;
   scanf("%d %d", &p, &q);
 
   for(int i = 0; i < p; i++)
      scanf("%d %d", &x[i], &y[i]);
 
   for(int i = 0; i < q; i++)
      scanf("%d %d %d %d", &x_left[i], &x_right[i], &y_down[i], &y_up[i]);
 
   go(p, q, 0);
 
   for(int i = 0; i < p; i++) 
      swap(x[i], y[i]);
 
   for(int i = 0; i < q; i++) {
      swap(x_left[i], y_down[i]);
      swap(x_right[i], y_up[i]);
   }
 
   memset(B, 0, sizeof(B)); // NOT Required! WHY?
 
   go(p, q, 1);
 
   for(int i = 0; i < q; i++) {
      unsigned long long int val = magic(ans[0][i]) + magic(ans[1][i]);
      printf("%llu\n", val);
   }
 
   return 0;
}
