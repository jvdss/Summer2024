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
    int n = 0;
    cin >> n; n++;
    vector<vector<int>> v(31, vector<int>(n));

    for(int i = 1; i < n; i++) cin >> v[0][i];
    // for(int i = 1; i < n; i++) cout << v[0][i]  << " \n"[i==n-1];

    for(int j = 1; j <=30; j++){
        for(int i = 1; i < n; i++){
            v[j][i] = v[j-1][ v[j-1][i] ];
            // p2j[i] = pj-1 [ pj-1[i] ]
        }
        
    }
    
    // for(int j = 0; j <=30; j++){
    //     cout << "P" << (1<< j) <<" | ";
    //     for(int i = 1; i < n; i++){
    //         cout << v[j][i]  << " \n"[i==n-1];
    //     }
    // }
    auto get = [&](int m){
        vector<int> t(n);
        bool first  = true;
        // cout << bitset<8>(m) << endl;
        for( int mask = 0; mask <= 30; mask++){
            if( m & ( 1 << mask)){
                if( first ){
                    // cout << " Copy " << (1<<mask) << endl;
                    for(int i = 1; i < n; i++)
                        t[i] = v[mask][i];
                    first = false;
                }else{
                    // cout << "Added " << (1<<mask) << endl;
                    for(int i = 1; i < n; i++){
                        t[i] = v[mask][ t[i] ];
                        // pt[i] = pv[ pt[i] ]
                    }
                }
            }
        }
        bool ok = true;
        for(int i = 1; i < n; i++){
            cout << t[i] << " \n"[i==n-1];
            // if( t[i] != i) ok = false;
        }

        return ok;
    };
    get(3);
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
