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
    vll v(n);
    FOR(i,n){
        int x; cin >> x;
        v[i] = x;
    }
    vector<pii> goods;
    map<int,int> mp;
    int last = 0;
    int it = 0;
    for(int i = 0; i < n ; i++){
        // cout << "Add " << v[i] << endl;
        mp[v[i]]++;
        if(mp[v[i]]==2){

            goods.pb({last,i});
            for(; it <=i; it++){
                // cout << "rem " << v[it] << endl;
                mp[v[it]]--;
            }
            // for(auto [x,f] : mp){
            //     cout << x << " " << f << endl;
            // }
            last = i+1;
            it = i+1;
        }
    }
    if( goods.size()==0){
        cout << -1 << endl; return;
    }
    cout << goods.size() << endl;
    for(auto [l,r] : goods){
        cout << l+1 << " " << r+1 << endl;
    }
    cout << 1LL*500000*(500000-1)/2 << endl;
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
