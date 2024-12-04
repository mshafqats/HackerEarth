/*
=====================
|  ID:   mshafqats  |
|  LANG: C++        |
=====================
Mohammad Shafqat Siddiqui
*/

#include <bits/stdc++.h>
#define fu(i, a, b) for(ll i = (a); i <= (b); i++)
#define fd(i, a, b) for(int i = (a); i >= (b); i--)
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const ll INF = (ll)1e18 + 5;
 
int n, q, k;
int a[N + 100];
vector<int> lis;
 
struct Fenwick
{
    vector<int> BIT;
    void init(int n)
    {
        BIT.resize(n + 5, 0);
    }
    void update(int x, int val)
    {
        for(int i = x; i <= N; i += (i & (-i))) {
            BIT[i]+=val;
        }
    }
    int get(int x)
    {
        int res = 0;
        for(int i = x; i >= 1; i -= (i &(-i))) {
            res+=BIT[i];
        }
        return res;
    }
};
Fenwick f;
 
struct dt
{
    int a, b, c, d, type;
    dt(int _type = 0, int _a = 0, int _b = 0, int _c = 0, int _d = 0)
    {
        type = _type;
        a = _a;
        b = _b;
        c = _c;
        d = _d;
    }
};
 
 
vector<dt> qr;
 
int giatri(int x)
{
    return lower_bound(lis.begin(), lis.end(), x) - lis.begin() + 1;
}
 
 
void read()
{
    cin >> n >> q >> k;
    fu(i, 1, n) {
        cin >> a[i];
        lis.push_back(a[i]);
    }
    f.init(N + 5);
    fu(i, 1, q) {
        int type;
        cin >> type;
        if(type == 0) {
            int id, val;
            cin >> id >> val;
            lis.push_back(val);
            qr.push_back({type, id, val, 0, 0});
        }
        else {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            lis.push_back(a);
            lis.push_back(b);
            lis.push_back(c);
            lis.push_back(d);
            qr.push_back({1, a, b, c, d});
        }
    }
    sort(lis.begin(), lis.end());
    lis.resize(unique(lis.begin(), lis.end()) - lis.begin());
    fu(i, 1, n) {
        a[i] = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin() + 1;
        f.update(a[i], 1);
    }
    fu(i, 0, (int)qr.size() - 1)
    {
        int type = qr[i].type;
        if(type == 0) {
            int id = qr[i].a;
            int val = qr[i].b;
            val = lower_bound(lis.begin(), lis.end(), val) - lis.begin() + 1;
            f.update(a[id], -1);
            a[id] = val;
            f.update(a[id], 1);
        }
        else {
            int a = qr[i].a;
            a = giatri(a);
            int b = qr[i].b;
            b = giatri(b);
            int c = qr[i].c;
            c = giatri(c);
            int d = qr[i].d;
            d = giatri(d);
            int x = max(a, c);
            int y = min(b, d);
            if(x > y) {
                cout << "Do not propose" << '\n';
            }
            else {
                int val = f.get(y) - f.get(x - 1);
                if(val >= k) cout << "Propose" << '\n';
                else cout << "Do not propose" << '\n';
            }
        }
    }
 
 
 
 
}
 
int main()
{
    //freopen("DC.inp","r",stdin);
    //freopen("DC.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);
 
    read();
}
