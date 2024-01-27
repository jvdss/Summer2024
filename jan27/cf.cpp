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

int n,m;
ll d[10101];
vector<pii> g[10101];
ll dijkstra(int st, int mx){
    FOR(i,n) d[i] = LINF;
    priority_queue<pair<ll,int>> pq;
    pq.push({0,st});
    d[st] = 0;
    while( pq.size() ){
        auto [ndist, u] = pq.top(); pq.pop();
        if( -ndist > d[u]) continue;
        for(auto [v,w] : g[u]){
            if( w <= mx){
                if(d[v] > d[u] + w){
                    d[v] = d[u] + w;
                    pq.push({-d[v], v});
                }
            }
        }
    }
    return d[n-1];
}
/* if interactive remove fastio endl */     
/* stop freaking out pls*/ 
void solve(){
    int x; cin >> n >> m >> x;
    FOR(i,m){
        int a,b,w; cin >> a >> b >> w;
        --a; --b;
        g[a].pb({b,w});
        g[b].pb({a,w});
    }
    ll bestDis = dijkstra(0, 1e9+1);
    ll mxDis = bestDis*( ld( 1 + (1.0*x)/100));

    int l = 0;
    int r = 1e9;
    while(r > l + 1){
        int mid = ( r+l)/2;
        auto ret = dijkstra(0,mid);
        if(ret <= mxDis) r = mid;
        else l = mid;
    }
    cout << r << endl;
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
