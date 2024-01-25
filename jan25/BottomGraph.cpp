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
/* if interactive remove fastio endl */     
/* stop freaking out pls*/ 
void solve(){
    while( cin >> n and n){
        int m; cin >> m;
        FOR(i,n) g[i][0].clear(), g[i][1].clear();
        FOR(i,n) vis[i][0] = vis[i][1] = 0;

        FOR(i,m){
            int a,b; cin >> a >> b;
            --a; --b;
            g[a][0].pb(b);
            g[b][1].pb(a);
        }
        int sComp = kosaraju();
        vi flag(sComp, 1);

        FOR(i,n){
            for(auto x : g[i][0]){
                if(comp[x]!=comp[i])
                    flag[comp[i]] = false;
            }
        }

        vi ans;
        FOR(i,n){
            if( flag[comp[i]] ){
                ans.pb(i+1);
            }
        }

        for(int i = 0; i < sz(ans); i++){
            cout << ans[i] << " \n"[i==sz(ans)-1];
        }

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
