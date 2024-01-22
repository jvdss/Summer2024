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
 
//  0 nao processei 
//  1 to processando
//  2 ja terminei de processar
vi g[MAX];
int par[MAX], cor[MAX], behind[MAX];
int st,en;
bool dfs(int u, int p = -1){
    cor[u] = 1;
    for(auto v : g[u]){
        if(v==p) continue;
        if(cor[v]==1 and behind[u]-behind[v]>=2){
            st = v; en = u;
            return true;
        }
        behind[v] = behind[u] + 1;
        par[v] = u;
        auto ret = dfs(v,u);
        if(ret) return ret;
    }
    return false;
}
/* if interactive remove fastio endl */     
/* stop freaking out pls*/ 
void solve(){
    int n,m; cin >> n >> m;
    FOR(i,m){
        int a,b; cin >> a >> b;
        --a; --b;
        // cout << a << " " << b << endl;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    FOR(i,n) if(cor[i]==0){
        st = en = -1;
        auto ok = dfs(i);
        if(ok){
            vi path; path.pb(st+1);
            while(en!=st){
                path.pb(en+1);
                en = par[en];
            }
            path.pb(st+1);
            cout << sz(path) << endl;
            PR(path);
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
    
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
