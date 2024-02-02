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
    vector<pair<string,int>> v(n);
    FOR(i,n){
        string s; cin >> s;
        v[i].ff = string(50,'a');
        for(int j = 0; j < 50; j++){
            if( j >= s.size()){
                v[i].ff[j] = s.back();
            }else{
                v[i].ff[j] = s[j];
            }
        }
        v[i].ss = s.size();
    }
    sort(all(v) , []( pair<string,int> a, pair<string,int> b) {
        if(a.ff==b.ff) return a.ss > b.ss;
        return a.ff < b.ff;
    });
    string ret = "";
    FOR(i,n){
        ret += v[i].ff.substr(0, v[i].ss) ;
        cout << v[i].ff.substr(0, v[i].ss) << endl;
    }
    cout << ret << endl;
    vector<string> at = { "aazzaz","abbbbb"};
    sort(all(at));
    FOR(i,2){
        cout << at[i] << endl;
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
 