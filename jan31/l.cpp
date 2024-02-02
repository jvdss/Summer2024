#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i_ , e_ )  for(int i_ = (int) 0 ; i_ <  (int) e_ ; ++i_ )
#define PR( v_ ) for(auto x_ : v_) cout << x_ << " "; cout << endl;
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
#define pb push_back
#define ss second
#define ff first
#define endl '\n'
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
 
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;
const int MAX  = 2e5+4;
const ll MOD  = 998244353; 

void solve(){
    int n; cin >> n;
    vector<pii> rp(n);
    vector<pii> points(n);
    FOR(i,n){
        int x,y; cin >> x >> y;
        points[i] = {x,y};
        rp[i] = { (x + y), (x - y)};
    }
    int xa,xi,ya,yi;
    xa = ya = -INF; xi = yi = INF;
    int a = 0,b = 0;
    for(auto [x,y] : rp){
        a+= x; b+= y;
    }
    a/=n; b/=n;
    // cout << a << " " << b << endl;
    int x = (a+b)/2;
    int y = x -b;
    cout << x << " " << y << endl;
    
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1; 
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
