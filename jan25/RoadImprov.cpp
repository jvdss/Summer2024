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

vector<pii> g[MAX];
vi days[MAX];
int mark[MAX];

void dfs(int u, int p = -1, int time_used = -1){
    int t = 1;
    if(t==time_used) t++;

    for(auto [v,id] : g[u]){
        if(v==p) continue;
        if(t==time_used) t++;

        days[t].pb(id);
        dfs(v,u,t);
        t++;
    }
}

/* if interactive remove fastio endl */     
/* stop freaking out pls*/ 
void solve(){
    int n; cin >> n;
    int id = 1;
    int maior_dia = 0;

    FOR(i,n-1){
        int a,b; cin >> a >> b; --a; --b;

        g[a].pb({b, id});
        g[b].pb({a, id});
        maior_dia = max({maior_dia, sz(g[a]), sz(g[b])});
        id++;
    }
   
    dfs(0);  
    
    cout << maior_dia << endl;
    for(int d = 1; d <=maior_dia; d++){
        cout << sz(days[d]) << " ";
    
        for(int i = 0; i < sz(days[d]); ++i){
            cout << days[d][i] << " \n"[i==sz(days[d])-1];
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
