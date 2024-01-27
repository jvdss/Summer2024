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
    int n; cin >> n;
    vi v(n); FOR(i,n) cin >> v[i];
    vi sv(v); sort(all(sv));
    ll ans = 0;
    int first = -1;

    for(int i = n-1; i >=0; --i){
        if(v[i]==sv[i]){
            continue;
        }
        first = i;
        break;
    }

    if(first != -1){
        int mx = 0;
        for(int i = 0; i < first; i++){
            if( v[i] > v[first]) {
                mx = i;
                break;
            }
        }
        for(int i = first; i - 1 >= mx; i--){
            swap(v[i],v[i-1]);
        }

    }

    PR(sv);
    PR(v);
    for(int i = 0; i <n; ++i){
        ans += 1LL*v[i]*(i+1);
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
