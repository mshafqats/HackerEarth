/*
=====================
|  ID:   mshafqats  |
|  LANG: C++        |
=====================
Mohammad Shafqat Siddiqui
*/

#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define each(it,o) for(auto it= (o).begin(); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define inrep int t;cin>>t; while(t--)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii > vpii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll > vpll;
typedef vector<string> vs;
typedef long double ld;
 
template<typename T> ostream& operator<< ( ostream &o,vector<T> v ) {
    if ( v.size() >0 )
        o<<v[0];
    for ( unsigned   i=1; i<v.size(); i++ )
        o<<" "<<v[i];
    return o<<endl;
}
template<typename U,typename V> ostream& operator<< ( ostream &o,pair<U,V> p ) {
    return o<<"("<<p.first<<", "<<p.second<<") ";
}
template<typename T> istream& operator>> ( istream &in,vector<T> &v ) {
 
    for ( unsigned   i=0; i<v.size(); i++ )
        in>>v[i];
    return in;
}
struct Frac {
    ll n,d;
    Frac ( ll nn, ll dd ) :n ( nn ),d ( dd ) {
        if ( d<0 ) {
            d=-d;
            n=-n;
        }
        reduce();
    }
    Frac &operator*= ( const Frac &o ) {
        n*=o.n;
        d*=o.d;
        return *this;
    }
    Frac &operator+= ( const Frac &o ) {
        ll d2=d*o.d;
        n=n*o.d+o.n*d;
        d=d2;
        return *this;
    }
    Frac &operator-= ( const Frac &o ) {
        ll d2=d*o.d;
        n=n*o.d-o.n*d;
        d=d2;
        return *this;
    }
    Frac &operator/= ( const Frac &o ) {
        n*=o.d;
        d*=o.n;
        if ( d<0 ) {
            d=-d;
            n=-n;
        }
        return *this;
    }
    Frac operator-() {
 
        return Frac ( -n,d );
 
    }
    Frac operator+ ( const Frac &o ) {
        return Frac ( *this ) +=o;
    }
    Frac operator/ ( const Frac &o ) {
        return Frac ( *this ) /=o;
    }
    Frac operator* ( const Frac &o ) {
        return Frac ( *this ) *=o;
    }
    Frac operator- ( const Frac &o ) {
        return Frac ( *this ) -=o;
    }
    ll gcd ( ll a , ll b ) {
        if ( b==0 ) return a;
        a%=b;
        return gcd ( b,a );
    }
 
    void reduce() {
        if ( !n ) return;
        ll g=gcd ( abs ( n ),abs ( d ) );
        n/=g;
        d/=g;
    }
    Frac mediant ( const Frac &o ) {
        return Frac ( n+o.n, d+o.d );
    }
};
ostream &operator<< ( ostream &os, const Frac& f ) {
    return os<<f.n<<'/'<<f.d;
}
bool operator== ( const Frac &f1, const Frac &f2 ) {
    ll d=  f1.n*f2.d-f2.n*f1.d;
    return !d;
}
bool operator< ( const Frac &f1, const Frac &f2 ) {
    ll d=  f1.n*f2.d-f2.n*f1.d;
    return d<0;
}
bool operator<= ( const Frac &f1, const Frac &f2 ) {
    ll d=  f1.n*f2.d-f2.n*f1.d;
    return d<=0;
}

#define gc getchar_unlocked
void scan ( int &x ) {
    int c = gc();
    x = 0;
    for ( ; ( c<48 || c>57 ); c = gc() );
    for ( ; c>47 && c<58; c = gc() ) {
        x = ( x << 1 ) + ( x << 3 ) + c - 48;
    }
}
template<typename T> void scan ( vector<T> &v ) {
    for ( T &r:v ) scan ( r );
}

template<typename U>
struct node {
    U x;
    int p, cnt;
    node<U> *l, *r;
 
    node ( U _x ) : x ( _x ), p ( rand() ), cnt ( 1 ), l ( NULL ), r ( NULL ) {}
    void recalc() {
        cnt = 1;
        if ( l ) cnt += l->cnt;
        if ( r ) cnt += r->cnt;
    }
};

template<typename T>
struct OrderSet {
 
    typedef node<T> *np;
 
    np merge ( np l, np r ) {
        if ( !l || !r ) return l ? l : r;
        if ( l->p < r->p ) {
            l->r = merge ( l->r, r );
            l->recalc();
            return l;
        } else {
            r->l = merge ( l, r->l );
            r->recalc();
            return r;
        }
    }
 
    pair<np,np> split ( np v, T x ) {
        np l,r;
        l = r = NULL;
        if ( !v ) return mp ( l,r );
        if ( v->x < x ) {
            tie ( v->r,r ) = split ( v->r, x );
            l = v;
        } else {
            tie ( l,v->l ) = split ( v->l, x );
            r = v;
        }
        v->recalc();
        return mp ( l,r );
    }
    pair<np,np> splitLeft ( np v, T x ) {
        np l,r;
        l = r = NULL;
        if ( !v ) return mp ( l,r );
        if ( v->x <= x ) {
            tie ( v->r,r ) = splitLeft ( v->r, x );
            l = v;
        } else {
            tie ( l,v->l ) = splitLeft ( v->l, x );
            r = v;
        }
        v->recalc();
        return mp ( l,r );
    }
 
    np root;
    OrderSet() : root ( NULL ) {}
    OrderSet ( np n ) : root ( n ) {}
 
    static  int lcount ( np n ) {
        return n->l?n->l->cnt:0;
    }
    void insert ( T x ) {
        np l, r;
        tie ( l,r ) = split ( root, x );
        root = merge ( merge ( l, new node<T> ( x ) ), r );
    }
    void insertUnique ( T x ) {
        np l, m, r;
        tie ( l,m ) =  split ( root, x );
        tie ( m,r ) =splitLeft ( m, x );
        if ( !m ) m=new node<T> ( x );
        root=merge ( merge ( l,m ),r );
    }
    void eraseOne ( T x ) {
        np l, m, r;
        tie ( l,m ) =  split ( root, x );
        tie ( m,r ) =splitLeft ( m, x );
        m=merge ( m->l,m->r );
        root=merge ( merge ( l,m ),r );
 
    }
    void erase ( T x ) {
        np l, m, r;
        tie ( l,m ) =  split ( root, x );
        tie ( m,r ) =splitLeft ( m, x );
        root = merge ( l, r );
    }
    np getKths ( np n, int k ) {
        if ( !n ) return NULL;
        int lc=lcount ( n );
        if ( lc==k-1 ) return n;
        if ( lc<k ) return getKths ( n->r,k-lc-1 );
        return getKths ( n->l,k );
    }
 
    np getKths ( int k ) {
        return getKths ( root,k );
 
    }
    int cntSmaller ( np n, T x ) {
        if ( !n ) return 0;
        if ( x<= n->x ) return cntSmaller ( n->l,x );
        return lcount ( n ) +1+cntSmaller ( n->r,x );
    }
    int cntSmaller ( T x ) {
        return cntSmaller ( root,x );
    }
    int cntRange ( T s, T e ) {
        return cntSmaller ( root,e )-cntSmaller ( root,s );
    }
    bool contains ( np n, T x ) {
        if ( !n ) return 0;
        if ( n->x==x ) return 1;
        if ( n->x>x ) return contains ( n->l,x );
        return contains ( n->r,x );
    }
    bool contains ( T x ) {
        return contains ( root,x );
    }
    int size() const {
        return root ? root->cnt : 0;
    }
};
void test() {
 
    OrderSet<Frac> vals;
 
    Frac f11=Frac ( 1,1 );
    Frac f12=Frac ( 1,2 );
    Frac f13=Frac ( 1,3 );
    Frac f12m=f12-Frac ( 1,1 );
    cout<<"f12m"<<f12m<<endl;
    vals.insert ( f12m );
    vals.insert ( f12m );
    vals.insert ( f12 );
    vals.insert ( f12 );
    vals.insert ( f13 );
    vals.insert ( f13 );
    cout<<vals.cntSmaller ( f12m ) <<endl;
    cout<<vals.cntSmaller ( f13 ) <<endl;
    cout<<vals.cntSmaller ( f12 ) <<endl;
    cout<<vals.cntSmaller ( f11 ) <<endl;
    vals.eraseOne ( f13 );
    cout<<vals.cntSmaller ( f12m ) <<endl;
    cout<<vals.cntSmaller ( f13 ) <<endl;
    cout<<vals.cntSmaller ( f12 ) <<endl;
    cout<<vals.cntSmaller ( f11 ) <<endl;
    vals.erase ( f12 );
    cout<<vals.cntSmaller ( f12m ) <<endl;
    cout<<vals.cntSmaller ( f13 ) <<endl;
    cout<<vals.cntSmaller ( f12 ) <<endl;
    cout<<vals.cntSmaller ( f11 ) <<endl;
}
 
struct LK {
    const uint n,k;
    const vector<vpii> &adj;
    vpii par;
    void dfs0 ( int i, pii pa ) {
        par[i]=pa;
        for ( pii p: adj[i] ) if ( p!=pa ) dfs0 ( p.first,mp ( i,p.second ) );
    }
    LK ( const vector<vpii> &aa, int kk ) :n ( aa.size() ),k ( kk ),adj ( aa ),par ( n ) {
        dfs0 ( 0,mp ( -1,0 ) );
    }
 
    double EPS1=1.e-12;
    double EPS2=1.e-10;
    OrderSet<double> vals;
    double add=0;
 
    ll dfs ( int no, int pa, double b ) {
        ll cnt= vals.cntSmaller ( -add+ EPS1 );
        for ( pii p: adj[no] ) if ( p.first!=pa ) {
                vals.insert ( -add );
                double addO=add;
                add+=p.second-b;
                cnt+=dfs ( p.first,no,b );
                add=addO;
                vals.eraseOne ( -add );
            }
        return cnt;
    }
 
 
    ll cntSmaller ( double bound ) {
        vals=OrderSet<double>();
        add=0;
        return dfs ( 0,-1,bound );
    }
 
    OrderSet<double> vals1;
    OrderSet<double> vals2;
    double add1=0;
    double add2=0;
 
    int dfs2 ( int no, int pa, double mi, double ma ) {
        ll cnt= vals1.cntSmaller ( -add1+ EPS1 );
        ll cnt2=vals2.cntSmaller ( -add2+EPS1 );
        if ( cnt2!=cnt ) return no;
        for ( pii p: adj[no] ) if ( p.first!=pa ) {
 
                double add1o=add1;
                double add2o=add2;
 
                vals1.insert ( -add1 );
                vals2.insert ( -add2 );
                add1+=p.second-mi;
                add2+=p.second-ma;
                int r= dfs2 ( p.first,no,mi,ma );
                if ( r>=0 ) return r;
                add1=add1o;
                add2=add2o;
                vals1.eraseOne ( -add1 );
                vals2.eraseOne ( -add2 );
            }
        return -1;
 
    }
 
    Frac findPath ( double mi, double ma ) {
        int r=dfs2 ( 0,-1,mi,ma );
        int u=r;
        int cnt=0;
        ll su=0;
 
        double leastd=INF;
        Frac bestf ( 0,1 );
        while ( 1 ) {
            cnt++;
            pii p=par[u];
            u=p.first;
            if ( u<0 ) break;
            su+=p.second;
            double v=su/double ( cnt );
            if ( abs ( ma-v ) <leastd ) {
                leastd=abs ( ma-v );
                bestf=Frac ( su,cnt );
            }
            if ( v<=ma+2*EPS2 &&v>mi ) return Frac ( su,cnt );
 
        }
        return bestf;
    }
    Frac run() {
        double mi=0,ma=INF;
        double eps=EPS2;
        while ( eps<ma-mi ) {
            double s= ( ma+mi ) /2;
            ll r=cntSmaller ( s );
            if ( r<k ) mi=s;
            else ma=s;
        }
        return findPath ( mi,ma );
        return Frac ( 0,1 );
    }
};
struct SS {
    const uint n,k;
    const vector<vpii> &adj;
    vi dep;
 
    void dfs ( int no, int p, int d ) {
        dep[no]=d;
        for ( pii q: adj[no] ) if ( q.first!=p ) dfs ( q.first,no,d+1 );
    }
 
    SS ( const vector<vpii> &aa, int kk ) :n ( aa.size() ),k ( kk ),adj ( aa ), dep ( n ) {
        dfs ( 0,-1,0 );
    }
    Frac  run() {
        vector<vpii>  down ( n );
        vpii up ( n,mp ( -1,-1 ) );
        rep ( i,n ) {
            for ( pii p: adj[i] ) if ( dep[i]<dep[p.first] ) down[i].push_back ( p );
                else up[i]=p;
        }
        priority_queue<pair<Frac, pii>> cands;
        vector<pair<Frac,pii>> current;
        rep ( i,n ) {
            pii p= up[i];
            if ( up[i].first<0 ) continue;
            Frac f ( p.second,1 );
            if ( cands.size() ==k &&f<cands.top().first ) cands.pop();
            if ( cands.size() <k ) cands.push ( mp ( f,mp ( i,p.first ) ) );
        }
 
 
        vector<set<int>> used ( n );
        while ( cands.size() ) {
            current.push_back ( cands.top() );
            int d,u;
            tie ( d,u ) =current.back().second;
            used[d].insert ( u );
            cands.pop();
        }
        for ( auto x: current ) cands.push ( x );
        vector<set<int>> taken ( n );
        rep ( i,k-1 ) {
            int mi=min_element ( all ( current ) )-current.begin();
            int u,d;
            tie ( d,u ) =current[mi].second;
            assert ( !taken[d].count ( u ) );
            taken[d].insert ( u );
            Frac cw=current[mi].first;
            pii p=up[u];
            while ( p.first>=0 ) {
                if ( Frac ( p.second,1 ) <cw ) break;
                cw=cw.mediant ( Frac ( p.second,1 ) );
                if ( used[d].count ( p.first ) ) continue;
                if ( cands.size() ==k &&cw<cands.top().first ) cands.pop();
                if ( cands.size() <k ) {
                    used[d].insert ( p.first );
                    current.push_back ( mp ( cw,mp ( d,p.first ) ) );
                    cands.push ( current.back() );
                } else break;
                p=up[p.first];
            }
            priority_queue<pair<Frac,pii>, vector<pair<Frac,pii>>, greater<pair<Frac,pii>>> pq;
            pq.push ( mp ( current[mi].first,mp ( d,u ) ) );
            while ( !pq.empty() ) {
                Frac cw=pq.top().first;
                if ( cands.size() ==k && cands.top().first<=cw ) break;
                int u,d;
                tie ( d,u ) =pq.top().second;
                pq.pop();
                for ( pii p: down[d] ) {
                    Frac nv=Frac ( p.second,1 );
                    if ( cw<nv ) {
                        Frac nw=nv.mediant ( cw );
                        if ( used[p.first].count ( u ) ) continue;
                        used[p.first].insert ( u );
                        if ( cands.size() ==k &&nw<cands.top().first ) cands.pop();
                        if ( cands.size() <k ) {
                            current.push_back ( mp ( nw,mp ( p.first,u ) ) );
                            cands.push ( current.back() );
                            pq.push ( current.back() );
                        }
                    }
                }
            }
 
            vector<pair<Frac,pii>> nxt;
            rep ( i,current.size() ) {
                if ( i==mi ) continue;
                if ( current[i].first<=cands.top().first ) nxt.push_back ( current[i] );
            }
            swap ( current,nxt );
        }
 
 
        int mi=min_element ( all ( current ) )-current.begin();
        return current[mi].first;
    }
};
int main() {
    int n,k;
    scan ( n );
    scan ( k );
    vector<vpii> adj ( n );
    rep ( i,n-1 ) {
        int u,v,c;
        scan ( u );
        scan ( v );
        scan ( c );
        u--;
        v--;
        adj[u].push_back ( mp ( v,c ) );
        adj[v].push_back ( mp ( u,c ) );
    }
 
    if ( n>100000 ) {
        SS ss ( adj,k );
        Frac res=ss.run();
        res.reduce();
        cout<<res<<endl;
        return 0;
    }

    LK lk ( adj,k );
    Frac res=lk.run();
    res.reduce();
    cout<<res<<endl;
    return 0;
}
