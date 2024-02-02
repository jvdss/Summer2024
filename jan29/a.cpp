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
int mx[MAX];
int dfs(int u, int p = -1){
    int cnt = 0;
    bool isleaf = true;
    for(auto v: g[u]){
        if(v==p) continue;
        isleaf = false;
        int ret = dfs(v,u);
        cnt += ret;
        mx[u] = max(mx[u], ret + 1);
    }
    if(isleaf) cnt++;
    return cnt;
    
}
/* if interactive remove fastio endl */     
/* stop freaking out pls*/ 
void solve(){
    int n; cin >> n;
    FOR(i,n-1){
        int a,b; cin >> a >> b;
        --a; --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0);
    cout << mx[0] << endl;
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
