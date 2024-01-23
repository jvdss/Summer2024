#include <bits/stdc++.h>
using namespace std;

#define FOR(i_ , e_ )  for(int i_ = (int) 0 ; i_ <  (int) e_ ; ++i_ )
#define PR( v_ ) for(auto x_ : v_) cout << x_ << " "; cout << endl;
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
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
vector<int> gi[MAX]; // grafo invertido
int vis[MAX];
stack<int> S;
int comp[MAX]; // componente conexo de cada vertice

void dfs(int k) {
	vis[k] = 1;
	for (int i = 0; i < (int) g[k].size(); i++)
		if (!vis[g[k][i]]) dfs(g[k][i]);

	S.push(k);
}

void scc(int k, int c) {
	vis[k] = 1;
	comp[k] = c;
	for (int i = 0; i < (int) gi[k].size(); i++)
		if (!vis[gi[k][i]]) scc(gi[k][i], c);
}

int kosaraju() {
	for (int i = 0; i < n; i++) vis[i] = 0;
	for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);

	for (int i = 0; i < n; i++) vis[i] = 0;
    int c = 0;
	while (S.size()) {
		int u = S.top();
		S.pop();
		if (!vis[u]){
            scc(u, c);
            c++;
        }
	}
    return c;
}

int dfs_comp(int u, vector<set<int>>& ng, vi& vis_comp){
    vis_comp[u] = 1;
    bool children = false;
    int ret = 0;
    for(auto x : ng[u]) if(!vis_comp[x]){
        children = true;
        ret += dfs_comp(x,ng,vis_comp);
    }
    if(!children)
        return 1;

    return ret;
}

void solve(){

    int m; cin >> n >> m;

    
    FOR(i, n) g[i].clear();
    FOR(i, n) gi[i].clear();
    FOR(i, n) vis[i] = 0;
    vector<pii> edges;
    FOR(i, m){
        int a, b; cin >> a >> b;

        a--, b--;
        
        g[a].pb(b);
        edges.pb({a,b});
        gi[b].pb(a);
        
            
    }
    int c = kosaraju();
    if( n== 1 or c==1){
        cout << 0 << endl; return;
    }
    vector<set<int>> ng(c);
    for(auto [a,b] : edges){
        if(comp[a]!=comp[b]){
            ng[comp[a]].insert(comp[b]);
        }
    }

    vi vis_comp(c,0);
    ll ans = 0;
    int roots =0;
    for(int i = 0; i < c; i++) if(!vis_comp[i]){
        roots++;
        
        ans += dfs_comp(i,ng,vis_comp) - 1 ;
    }

    ans += roots;
    cout << ans << endl;
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

