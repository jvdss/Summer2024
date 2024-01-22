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
vector<vector<int>> g;
stack<int> s;
vector<int> id, art;

int dfs_art(int i, int& t, int p = -1){
    int lo = id[i] = t++;

    s.push(i);

    for(int j: g[i]) if(j != p){
        if(id[j] == -1){
            int val = dfs_art(j, t, i);
            lo = min(lo, val);

            if(val >= id[i]){
                art[i]++;
                while(s.top() != j) s.pop();
                s.pop();
            }
        }
        else lo = min(lo, id[j]);
    }

    if(p == -1 and art[i]) art[i]--;

    return lo;
}

void compute_art(){
    id = vector<int>(n, -1);
    art = vector<int>(n, 0);
    int t = 0;

    FOR(i, n) if(id[i] == -1)
        dfs_art(i, t, -1);
}
 
/* if interactive remove fastio endl */     
/* stop freaking out pls*/ 
void solve(){
    int m; cin >>n >>  m;

    g.resize(n);

    FOR(i, m){

        int a, b; cin >> a >> b;

        a--, b--;

        g[a].pb(b);
        g[b].pb(a);
    }

    int count = 0LL;

    vector<int> ans;

    compute_art();

    FOR(i, n){
        if(art[i] >= 1){
            count++;
            ans.pb(i + 1);
        }
    }

    cout << count << endl;

    FOR(i, count) cout << ans[i] << " \n"[i==count-1];
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
