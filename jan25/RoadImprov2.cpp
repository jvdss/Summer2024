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
int mark[MAX];
vector<tuple<int,int,int>> days;
int maior_dia;

void addDay(int u, int v, int d){
    if(u > v) swap(u,v);
    maior_dia = max(maior_dia, d);
    
    days.push_back({d, u, v});
}

void dfs(int u, int p = -1, int time_used = -1){
    int t = 1;
    if(t==time_used) t++;

    for(auto v : g[u]){
        if(v==p) continue;
    
        if(mark[v]==0 and mark[u]==0){
            mark[v] = mark[u] = 1;
            if(t==time_used) t++;

            addDay(u,v,t);
            dfs(v,u,t);
            t++;

        }else if( mark[v]==0 and mark[u]==1 ){
            if(t==time_used) t++;
            
            addDay(u,v,t);
            dfs(v,u,t);
            t++;
        }
    }
}
/* if interactive remove fastio endl */     
/* stop freaking out pls*/ 
void solve(){
    int n; cin >> n;
    int id = 1;
    map<pii,int> idAresta;
    FOR(i,n-1){
        int a,b; cin >> a >> b; --a; --b;
        if(a > b) swap(a,b);
        idAresta[{a,b}] = id++;
        g[a].pb(b);
        g[b].pb(a);
    }
   
    maior_dia = 0;
    dfs(0);  
    
    vector<vi> ans( maior_dia + 1 );
    FOR(i,n-1){
        auto [d,a,b] = days[i];
        ans[d].pb( idAresta[{a,b}] );
    }

    cout << maior_dia << endl;
    for(int d = 1; d <=maior_dia; d++){
        cout << sz(ans[d]) << " ";
    
        for(int i = 0; i < sz(ans[d]); ++i){
            cout << ans[d][i] << " \n"[i==sz(ans[d])-1];
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
