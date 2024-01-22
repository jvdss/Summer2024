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
vi tam;
vi subsize;
void dfs1(int u, int p = -1){
    for(auto v : g[u]){
        if(v==p) continue;
        dfs1(v,u);
        subsize[u] = max(subsize[u], subsize[v] +1);
    }
}



// armazena a quantidade de vertices que serao removidos caso
// o i vertice seja interrogado
void dfs(int u = 0, int p = -1, int up = 0){
    int id = -1;
    tam[u] = up+1;
    for(auto x : g[u]){
        if(x==p) continue;
        if(id==-1) id = x;
        if(subsize[id] < subsize[x]) id = x;
    }
    for(auto v : g[u]){
        if(v==p) continue;
        if(v==id){
            dfs(v,u,up+1);
        }else{
            dfs(v,u,0);
        }
    }
    
}
/* if interactive remove fastio endl */     
/* stop freaking out pls*/ 
void solve(){
    int n,k; cin >> n >> k;
    for(int i = 0; i <n-1 ; ++i){
        int a; cin >> a; --a;
        g[a].pb(i+1);
    }
    tam.resize(n,0);
    subsize.resize(n,0);
    
    dfs1(0);
    dfs(0,-1,0);

    vi ans; 
    FOR(i,n) if(sz(g[i])==0){
        ans.pb(tam[i]);
        // cout << i+1 << " " << subsize[i] << " " << tam[i] << endl;
    }
    sort(rall(ans));
    ll ret = 0;
    FOR(i,sz(ans)){
        if(k==0) break;
        ret += ans[i];
        k--;
    }
    cout << ret << endl;

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
