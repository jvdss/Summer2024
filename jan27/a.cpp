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
    int n,s; cin >> n >> s;
    vector<tuple<int,int,int>> jobs(n);
    vector<tuple<int,int,int>>  events;
    FOR(i,n){
        int l,r,c; cin >> l >> r >> c;
        // saida r - > negativo
        // entrada l - > positivo
        jobs[i] = {l,r,c};
        events.pb({l,  1, i});
        events.pb({r, -1, i});
    }
    set<ll> vasp; vasp.insert(0);
    multiset<ll> cur;
    vector<ll> bestbefore(n);
    sort(all(events), [&](auto a, auto b) {
        if(get<0>(a) == get<0>(b)) {
            return get<1>(a) > get<1>(b);
        }
        return get<0> (a) < get<0>(b);
    });
    // for(auto [d, e, id] : events){
    //     cout << d << " " << e << " " << id << endl;
    // }
    for(int i = 0; i < sz(events); ++i){
        auto [ day, e, id] = events[i];
        auto [ l, r, c ] = jobs[id];

        if( e < 0){ // termino de emprego
            ll now = bestbefore[id];
            ll to_rem = now -1LL*l*s + s - c;
            cur.erase( cur.find( to_rem ) );
            to_rem += 1LL*r*s;
            vasp.insert(to_rem);

        }else{ //entrada de emprego
            ll now = *vasp.rbegin() ;
            if( cur.size() > 0){
                now = max( now, *cur.rbegin() + 1LL*s*(l-1) );
            }

            ll to_add = now -1LL*l*s + s - c;

            bestbefore[ id ] = now ;
            cur.insert( to_add );
        }
    }
    // for(auto x : vasp){ cout << x << " " ; } 
    cout << *vasp.rbegin() << endl;
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
