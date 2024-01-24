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
 


vector<int> g[MAX];
vi mx_filho;
int par[MAX];
int depth[MAX];
void dfs_prof(int u, int p = -1){
    for(auto v : g[u]){
        if(v==p) continue;
        depth[v] = depth[u] + 1;
        par[v] = u;
        dfs_prof(v,u);
        mx_filho[u] = max(mx_filho[u], mx_filho[v]+1);
    }
}
/* if interactive remove fastio endl */     
/* stop freaking out pls*/ 
void solve(){
    int n,x; cin >> n >> x;
    --x;
    mx_filho.resize(n);
    FOR(i,n-1){
        int a,b; cin >> a >> b;
        --a; --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs_prof(0);
    // PR(mx_filho);
    int at = x;
    int mx = mx_filho[x], id = x;
    
    while(at!=0){
        if( depth[x] - depth[at] < depth[at] ){
            if(mx_filho[at] > mx){
                id = at; mx = mx_filho[at];
            }
        }
        if(depth[x] - depth[at] >= depth[at]) break;
        at = par[at];
    }
    
    
    cout << 2*(depth[id]+mx) << endl;
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
 