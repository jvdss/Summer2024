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

bool vis[MAX][2];
int comp[MAX];
vi posOrdem;
vi g[MAX][2];

void dfs(int u, int ind){
    vis[u][ind] = 1;
    for(auto v : g[u][ind]){
        if(vis[v][ind]) continue;
        
        if( ind == 1)
            comp[v] = comp[u];
        
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
        dfs(at,1);
        c++;
    }
    return c;
}

vi newg[MAX];
int newvis[MAX];
void trav(int u){
    newvis[u] = 1;
    for(auto v : newg[u]){
        if(newvis[v]) continue;
        trav(v);
    }
}
/* if interactive remove fastio endl */     
/* stop freaking out pls*/ 
void solve(){
    int m; cin >> n >> m;
    vector<pii> to_add;
    FOR(i,m){
        int a,b; cin >> a >> b;
        --a; --b;
        g[a][0].pb(b);
        to_add.pb({a,b});
        g[b][1].pb(a);
    }
    int c = kosaraju();

    vi fr(c,1);
    for(auto [a,b] : to_add){
        if(comp[a]!=comp[b]){
            newg[comp[b]].pb(comp[a]);
            fr[comp[a]] = 0;
        }
    }
    int pos = 0;
    for(int i = 0; i < c; ++i) if(fr[i]){
        pos = i; break;
    }
    trav(pos);

    FOR(i,c){
        if(!newvis[i]){
            cout << "0\n"; return;
        }
    }
    
    vi ans;
    FOR(i,n) if(comp[i]==pos) ans.pb(i+1);
    cout << sz(ans) << endl;
    PR(ans);
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
