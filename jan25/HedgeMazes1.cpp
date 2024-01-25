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
int vis[MAX];
int pre[MAX], low[MAX];
int timer;

vector<int> id, sz;

int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }

void join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b], id[b] = a;
}


void tarjan(int u, int p = -1){
    vis[u] = 1;
    pre[u] = low[u] = timer++;
    for(auto v : g[u]){
        if( v == p ) continue;

        if(vis[v]){
            low[u] = min(low[u],pre[v]);
        }else{
            tarjan(v,u);
            low[u] = min(low[u], low[v]);

            if( low[v] ==  pre[v]){
                join(v,u);
            }
        }
        
    }
}

/* if interactive remove fastio endl */     
/* stop freaking out pls*/ 
void solve(){
    int r,c,q; 
    while(cin >> r >> c >> q and r){
        
        FOR(i,c){    
            int a,b; cin >> a >> b;
            --a; --b;
            g[a].pb(b); g[b].pb(a);

        }

        timer = 0;
        id.resize(r), sz.resize(r, 1); 
        iota(id.begin(), id.end(), 0);
        tarjan(0);

        while(q--){
            int a,b; cin >> a >> b;
            --a; --b;
            cout << (find(a)==find(b) ? 'Y' : 'N') << endl;
        }
        cout << "-\n";
        FOR(i,r){
            g[i].clear();
            vis[i] = 0;
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
