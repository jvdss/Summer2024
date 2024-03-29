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

int n;
vector<int> g[MAX];
int dist[MAX], par[MAX];
void dfs(int u, int p = -1){
    // cout << "-> " << u << endl;
    for(auto v : g[u]){
        if(v==p) continue;
        dist[v] = dist[u] + 1;
        par[v] = u;
        dfs(v,u);
    }
}


/* if interactive remove fastio endl */     
/* stop freaking out pls*/ 
void solve(){
    cin >> n;
    FOR(i,n-1){
        int a,b; cin >> a >> b;
        --a; --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    dfs(0);
    set <pii> v;
    int ans = 0;
    FOR(i,n){
        v.insert({dist[i],i});
    }
    
    while(v.size()){
        auto [d,it] = *v.rbegin();

        if(d<=2) break;
        int nxt= par[it];
        
        auto itt = v.find({dist[ nxt ],nxt});
        if(itt != v.end())v.erase(itt);
        
        for(auto x : g[nxt]){
            itt = v.find({dist[x], x});
            if(itt != v.end())v.erase(itt);
        }
        ans++;
        
    }
    
    cout << ans << endl;
}


int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1; 
    // setIO("balancing"); 
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}