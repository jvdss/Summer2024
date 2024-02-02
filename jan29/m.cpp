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
    int n, m; cin >> n >> m;
    vector<tuple<int,int,int>> ranges(n);
    FOR(i,n){
        int l,r; cin >> l  >> r;
        ranges[i] = {l,r, i};
    }
    
    sort(all(ranges));
    vector<tuple<int,int,int>> events;
    int last = 1;

    FOR(i,n){
        auto [l,r, id] = ranges[i];
        if ( l <= last ) last = max(last,r+1);
        events.pb({l,0,i});
        events.pb({r,1,i});
    }

    sort(all(events));
    if( last != m+1){
        cout << "NO\n"; return;
    }

    int want = 1;
    multiset<int> open; open.insert(1e9+1);
    vi buy(n,1);

    for(int i = 0; i < sz(events); i++){
        auto [d, e, id] = events[i];
        auto [l, r, id1] = ranges[id];
        if(e==0){ // abre
            open.insert(l);
        }else{ // fecha

            open.erase( open.find(l));
 
            if( (want ==m + 1) or (*open.begin() <= want)){
                buy[id1] = 0;
            }else{
                want = r+1;
            }
        }
        
    }
    if(want!= m+1){
        cout << "NO\n"; return;
    }

    cout << "YES\n";
    vi ans;
    FOR(i,n) if(buy[i]){
        ans.pb(i+1);
    }
    cout << ans.size() << endl;
    for(int i = 0; i < (int)ans.size(); i++)
        cout << ans[i] << " \n"[i==(int)ans.size() -1];
    
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
