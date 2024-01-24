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

vi keys, vis;
vi g[MAX];
stack<int> hv;
void dfs(int u){
    vis[u]= 1;
    for(auto x : keys[u]){
        hv.push(x);
    }
    for(auto v : g[u]){
        if(vis[v]) continue;
    }
    
}
/* if interactive remove fastio endl */     
/* stop freaking out pls*/ 
void solve(){
    int n,k,m; 
    while(cin >> n >> k >> m and n!=-1){
        vi doors(k);
        keys.resize(n);
        vis.resize(n);
        FOR(i,n){
            keys[i].clear(); g[i].clear();
            vis[i] = 0;
        }
        map<int,set<int>> mp;
        FOR(i,k){
            int a, b; cin >> a >> b;
            --a; --b;
            keys[a].pb(i);
        }
        FOR(i,m){
            int a,b; cin >> a >> b;
            --a; --b;
            g[a].pb(b);
            g[b].pb(a);
        }
        dfs(0);
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
