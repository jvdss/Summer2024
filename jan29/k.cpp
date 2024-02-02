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
    int n,k; cin >> n >> k;
    vector<tuple<int,int,int>> events;
    vector<pii> ranges(n);
    FOR(i,n){
        int l,r; cin >> l >> r;
        events.pb({r,1,i});
        events.pb({l,-1,i});
        ranges[i] = {l,r};
    }
    sort(all(events) , [&](auto a , auto b){
        if( get<0>(a)== get<0>(b))
            return get<1>(a) < get<1>(b);
        return get<0>(a) < get<0>(b);
    });

    int open = 0;
    multiset<int> open_l;
    vector<pii> ans;
    bool good = false;
    for( int i = 0; i < 2*n; i++){
        auto [ l, e, id] = events[i];
        if( e < 0){ // abre
            open++;
            open_l.insert(l);
            if(open >= k){
                good = true;
            }
        }else{// fecha
            open--;
            if( good and open < k){
                ans.pb({ max( ranges[id].ff, *open_l.begin()), l});
                good = false;
                auto to_rem = open_l.find( ranges[id].ff );
                if( to_rem != open_l.end())
                    open_l.erase( to_rem);
                
            }
        }
    }
    cout << ans.size() << endl;
    for(auto [l,r] : ans){
        cout << l << " " << r << endl;
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
