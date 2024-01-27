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
const int MOD  = 998244354; 
 
/* if interactive remove fastio endl */     
/* stop freaking out pls*/ 
void solve(){
    int n;
    while( cin >> n){
        map<int,int> digp, dign;
        vector<pii> v(n);
        FOR(i,n){
            int x,y; cin >> x >> y;
            v[i] = { x,y };
            digp[ x - y ]++;
            dign[ x + y ]++;
        }

        ll cnt = 0;
        FOR(i,n){
            auto [x,y] = v[i];
            int pp = digp[ x - y ];
            int pn = dign[ x + y ];
            cnt += max(0, pp - 1) + max(0, pn - 1);
        }
        
        ll div = 1LL*n*n;
        long double ans = ld(1.0*cnt/div);
        cout << fixed << setprecision(6) << ans << endl;
    }
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
