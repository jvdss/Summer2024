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

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

vi g[MAX];
vi leafs;
void dfs(int u, int p = -1){
    if(sz(g[u])==1) leafs.pb(u);

    for(auto v : g[u]){
        if(v==p) continue;
        dfs(v,u);
    }
}
/* if interactive remove fastio endl */     
/* stop freaking out pls*/ 
void solve(){
    int n; cin >> n;
    FOR(i,n-1){
        int a,b; cin >> a >> b; --a; --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    int root = 0;
    
    FOR(i,n) if(sz(g[i])!=1) root = i;
    dfs(root);

    vector<pii> create;
    int m = (sz(leafs) + 1)/2 ;
    
    int it = 0;
    for(; it + m < sz(leafs) ; ++it){
        create.push_back({leafs[it], leafs[it + m]});
    }

    if(sz(leafs)&1) create.push_back({leafs[it], root});
    
    cout << sz(create) << endl;
    for(auto [u,v] : create){
        cout << u+1 << " " << v+1 << endl;
    }
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1; 
    setIO("kingdom");
    // cin >> t;
    while(t--){
        solve();
    }   
    return 0;
}
