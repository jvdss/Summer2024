#include <bits/stdc++.h>
using namespace std;

#define FOR(i_ , e_ )  for(int i_ = (int) 0 ; i_ <  (int) e_ ; ++i_ )
#define PR( v_ ) for(auto x_ : v_) cout << x_ << " "; cout << endl;
#define mem(arr,x) memset(arr, x, sizeof arr);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
#define pf push_front
#define pb push_back
#define ff first
#define ss second
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

// void setIO(string s) {
//     freopen((s + ".in").c_str(), "r", stdin);
//     freopen((s + ".out").c_str(), "w", stdout);
// }

vector<int> g[MAX];
int behind[MAX];
bool vis[MAX];
int par[MAX];
int st,en;
void dfs(int u, int p = -1 ){
    vis[u] = 1;
    for(auto v : g[u]){
        if(v==p) continue;
        if(vis[v]){
            if(behind[u]-behind[v]>=2){
                st = v; en = u;
            }
            continue;
        }
        par[v] = u;
        behind[v] = behind[u] + 1;
        dfs(v,u);
    }
}

/* if interactive remove fastio endl */
/* stop freaking out pls*/
void solve(){
    int n,m; cin >> n >> m;
    FOR(i,m){
        int a,b; cin >> a >> b;
        --a; --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    FOR(i,n) if(!vis[i]){
        st = en = -1;
        dfs(i);
        if(st==-1){
            continue;
        }

        vi ans; ans.pb(st);
        while(en!=st){
            ans.pb(en);
            en = par[en];
        }
        ans.pb(st);
        cout << sz(ans) << endl;
        for(auto x : ans){
            cout << x+1 << " ";
        }cout << endl;
        return;
    }

    cout << "IMPOSSIBLE\n";
}   

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1; 
    // setIO("backforth"); 
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}