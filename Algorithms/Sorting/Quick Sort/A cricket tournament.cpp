/*
=====================
|  ID:   mshafqats  |
|  LANG: C++        |
=====================
Mohammad Shafqat Siddiqui
*/

#include <iostream>
#include <algorithm>
 
using namespace std;
 
template <typename T> inline void inp (T &n) {
    n = 0;
    int ch = getchar_unlocked (), sign = 1;
    while (ch < '0' || ch > '9') {
        if (ch == '-') sign = -1;    // only if also negative integer
        ch = getchar_unlocked ();
    }
    while (ch >= '0' && ch <= '9')
        n = (n << 3) + (n << 1) + ch - '0', ch = getchar_unlocked ();
    n *= sign;   // only if also negative integer
}
 
inline int inp () {
    int n = 0;
    int ch = getchar_unlocked (), sign = 1;
    while (ch < '0' || ch > '9') {
        if (ch == '-') sign = -1;    // only if also negative integer
        ch = getchar_unlocked ();
    }
    while (ch >= '0' && ch <= '9')
        n = (n << 3) + (n << 1) + ch - '0', ch = getchar_unlocked ();
    n *= sign;   // only if also negative integer
    return n;
}
 
template <typename T> inline void puti (T n, char lc) {
	if (0 == n) {
        putchar_unlocked ('0');
        if (lc) putchar_unlocked (lc);
        return;
	}
    bool sign = false;
	if (n < 0) sign = true, n = -n;
    char s[20]; int rdi =-1;
	while (n) {
		s [++rdi] = '0' + n % 10;
		n /= 10;
	}
    if (sign) putchar_unlocked ('-');
	while (rdi >= 0) putchar_unlocked (s [rdi--]);
	if (lc) putchar_unlocked (lc);
}
 
inline void inps (string &i) {
    i = "";
    char temp = getchar_unlocked ();
    while (temp == '\n' or temp == ' ') temp = getchar_unlocked ();
    while (temp != '\n' and temp != ' ' and temp != EOF) i += temp, temp = getchar_unlocked ();
}
 
int main () {
    ios::sync_with_stdio (0);
    cin.tie (0); cout.tie (0);
    int i, n;
    long long sm = 0;
    inp (n);
    int a [n];
    int b [n];
    for (i = 0; i < n; i++) inp (a [i]);
    for (i = 0; i < n; i++) inp (b [i]);
    sort (a, a + n, greater <int> ());
    sort (b, b + n);
    for (i = 0; i < n; i++) {
        if (a [i] > b [i]) sm += a [i] - b [i];
        else break;
    }
    puti (sm, '\n');
    return 0;
}
