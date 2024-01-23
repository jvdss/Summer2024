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
vector<vi> g, revg;
vi comp, vis, flags;
stack<int> S;

void dfs(int k) {
	vis[k] = 1;
	for (int i = 0; i < (int) g[k].size(); i++)
		if (!vis[g[k][i]]) dfs(g[k][i]);

	S.push(k);
}

void scc(int k, int c) {
	vis[k] = 1;
	comp[k] = c;
	for (int i = 0; i < (int) revg[k].size(); i++)
		if (!vis[revg[k][i]]) scc(revg[k][i], c);
}

void kosaraju(int &c) {
	for (int i = 0; i < n; i++) vis[i] = 0;
	for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);

	for (int i = 0; i < n; i++) vis[i] = 0;
    c = 0;
	while (S.size()) {
		int u = S.top();
		S.pop();
		if (vis[u]) continue;

        scc(u, c);
        c++;
	}
    
}
/* if interactive remove fastio endl */     
/* stop freaking out pls*/ 
void solve(){
    
    int m; cin >> n >> m;
    g.resize(n);revg.resize(n);
    FOR(i,n){ g[i].clear(); revg[i].clear();}
    
    vector<pii> edges;
    set<pii> aux;
    FOR(i,m){
        int a,b; cin >> a >> b; 
        --a; --b;    
        g[a].pb(b);
        revg[b].pb(a);
        edges.emplace_back(a,b);
        aux.insert({a,b});
    }

    vis.resize(n); comp.resize(n);
    int c;
    kosaraju(c);
    vector<set<int>> ng(n);
    vi rep(c, -1);
    for(auto [a,b] : edges){
        if(comp[a]!=comp[b]){
            ng[a].insert(b);
        }
        if(rep[comp[a]]==-1) rep[comp[a]] = a;
        if(rep[comp[b]]==-1) rep[comp[b]] = b;
    }

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
