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
 
/* if interactive remove fastio endl */     
/* stop freaking out pls*/ 
void solve(){
    int n, k; cin >> n >> k;
    vi outDegree(n), par(n,0), sizes(n,1);
    
    FOR(i,n-1){
        int a; cin >> a; --a;
        par[i+1] = a;
        outDegree[a]++;
    }
    
    vi distances;
    queue<int> q;

    FOR(i,n) if(outDegree[i]==0) q.push(i); 
    while(q.size()){
        int at = q.front(); q.pop();

        outDegree[par[at]]--;
        if(outDegree[par[at]]==0){
            sizes[par[at]] += sizes[at];
            q.push(par[at]);
    
        }else{
            distances.push_back(sizes[at]);
        }
    }

    ll ans = 0;
    k = min(sz(distances),k);
    while(k--){
        ans += distances.back();
        distances.pop_back();
    }

    cout << ans << endl;
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
