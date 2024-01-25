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
 
vi g[MAX]
int pre[MAX], low[MAX];
bool vis[MAX];
void dfs(int u, int p = -1){
    pre[u] = low[u] = t++;
    vis[u] = 1;
    int qtdFilhos = 0;
    for(auto v : g[u]){
        if(v==p) continue;
    }
}
void init(int n){
    t = 0;
    FOR(i,n){ 
        g[i].clear();
        vis[i] = 0;
    }
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);

    while(cin >> m and m){

        int n = 0;
        FOR(i,n){
            int s,t; cin >> s >> t;
            n = max({n,s,t});
            --s; --t;
            g[s].pb(t);
            g[t].pb(s);
        }

        init(n);

    }
}
