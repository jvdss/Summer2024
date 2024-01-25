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
const int MAX  = 1e5+4;
const int MOD  = 998244354; 

int n;
bool vis[MAX][2];
int comp[MAX];
ll k[MAX];
ll compk[MAX];
vi posOrdem;
vi g[MAX][2];

void dfs(int u, int ind){
    vis[u][ind] = 1;
    for(auto v : g[u][ind]){
        if(vis[v][ind]) continue;
        
        if( ind == 1){
            comp[v] = comp[u];
            compk[comp[v]] += k[v];
        }
        
        dfs( v, ind);
    }
    if( ind == 0 ){
        posOrdem.pb(u);
    }
}

int kosaraju(){
    FOR(i,n) if(!vis[i][0]) dfs(i,0);
    int c = 0;
    while( posOrdem.size()){
        int at = posOrdem.back();
        posOrdem.pop_back();
        if(vis[at][1]) continue;

        comp[at] = c;
        compk[c] += k[at];
        dfs(at,1);
        c++;
    }
    return c;
}

set<int> cg[MAX];

void trav(int u, int p = -1){
    vis[u][0] = 1;
    ll mx = 0;
    for(auto v : cg[u]){
        if(v ==p ) continue;
        if(!vis[v][0])trav(v,u);
        mx = max(mx,compk[v]);
    }
    compk[u] += mx;
}

/* if interactive remove fastio endl */     
/* stop freaking out pls*/ 
void solve(){
    int m; cin >> n >> m;
    FOR(i,n) cin >> k[i];
    FOR(i,m){
        int a,b; cin >> a >> b;
        --a; --b;
        g[a][0].pb(b);
        g[b][1].pb(a);
    }
    
    int c = kosaraju();
    
    FOR(i,n){
        for(auto v : g[i][0]){
            if(comp[v]!=comp[i]){
                cg[comp[v]].insert(comp[i]);
            }
        }
    }
    
    FOR(i,c) vis[i][0] = 0;
    ll best = 0;
    
    for(int i = c-1 ; i >=0; --i) if(!vis[i][0]){
        trav(i);
        best = max(best,compk[i]);
    }
    
    cout << best << endl;
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
