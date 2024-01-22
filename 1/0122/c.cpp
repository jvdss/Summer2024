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
 
// Kosaraju
//
// O(n + m)

int n, m;
vector<int> g[MAX];
vector<int> gi[MAX]; // grafo invertido
int vis[MAX];
stack<int> S;
int comp[MAX]; // componente conexo de cada vertice

void check(int u){

    vis[u] = 1;

    // cout << u << endl;

    for(auto x: g[u]){
        if(!vis[x]) 
            check(x);
    }

    return;
}

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

void kosaraju() {
    for (int i = 0; i < n; i++) vis[i] = 0;
    for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);

    for (int i = 0; i < n; i++) vis[i] = 0;
    while (S.size()) {
        int u = S.top();
        S.pop();
        if (!vis[u]) scc(u, u);
    }
}
/* if interactive remove fastio endl */     
/* stop freaking out pls*/ 
void solve(){

    cin >> n >> m;

    FOR(i,m){
        int a,b; cin >> a >> b;
        --a; --b;
        // cout << a << " " << b << endl;
        g[a].pb(b);
        gi[b].pb(a);
    }

    kosaraju();

    for(int i = 1; i < n; i++){
        if(comp[0] != comp[i]){


            cout << "NO" << endl;

            FOR(j, n) vis[j] = 0;

            check(0);

            if(!vis[i]) cout << 1 << ' ' << i + 1 << endl;
            else cout << i + 1<< ' ' << 1 << endl;

            return;
        }
    }

    cout << "YES" << endl;


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
