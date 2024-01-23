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

int n,m;
vector<vi> vis, ans;
vector<string>  g;
vector<pii> dir = { {0,1}, {1,0}, {-1,0}, {0,-1}};
bool check(int a,int b){
    return a>=0 and a <n and b >=0 and b < m;
}
void dfs(int a, int b){
    vis[a][b] = 1;
    for(auto [i,j] : dir){
        if(check(a+i,b+j) and g[a+i][b+j]=='*'){
            ans[a][b]++;
        }
    }
    for(auto [i,j] : dir){
        if(check(a+i,b+j) and vis[a+i][b+j]!=1 and g[a+i][b+j]=='.'){
            dfs(a+i,b+j);
            ans[a][b] += ans[a+i][b+j];
        }
    }

}
void dfs1(int a,int b, int hv){
    vis[a][b] = 2;
    ans[a][b] = hv;
    for(auto [i,j] : dir){
        if(check(a+i,b+j) and vis[a+i][b+j]!=2 and g[a+i][b+j]=='.'){
            dfs1(a+i,b+j,hv);
        }
    }
}
/* if interactive remove fastio endl */     
/* stop freaking out pls*/ 
void solve(){
    int k; cin >> n >> m >> k;
    g.resize(n);
    vis.resize(n,vector(m,0));
    ans.resize(n,vector(m,0));
    FOR(i,n) cin >> g[i];
    FOR(i,n) FOR(j,m) if(!vis[i][j] and g[i][j]=='.'){
        dfs(i,j);
        dfs1(i,j,ans[i][j]);
    }
    // FOR(i,n) FOR(j,m){
    //     cout << ans[i][j] << " \n"[j==m-1];
    // }
    while(k--){
        int a,b; cin >> a >> b;
        --a; --b;
        cout << ans[a][b] << endl;
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
