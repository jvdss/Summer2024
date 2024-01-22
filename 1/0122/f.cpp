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


vi g[MAX];
int cat[MAX];
int m, ans;
void dfs(int u, int p = -1,int at = 0, int mx = 0){
    bool leaf = true;
    for(auto v : g[u]){
        if(v==p) continue;
        leaf = false;
        if(cat[v]){
            dfs(v,u,at+1, max(mx,at+1) );
        }else{
            dfs(v,u,0,mx);
        }
    }
    if(leaf and mx <= m ){
        ++ans;
    }
}
/* if interactive remove fastio endl */     
/* stop freaking out pls*/ 
void solve(){
    int n; cin >> n >> m;
    ans = 0;
    FOR(i,n) cin >> cat[i];
    FOR(i,n-1){
        int a,b; cin >> a >> b;
        --a; --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0,-1,cat[0],cat[0]);
    cout << ans << endl;
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
