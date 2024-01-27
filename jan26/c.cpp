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
    int q, m; cin >> q >> m;
    // ques m- papers
    vector<vi> gab(q,vi(4,1));
    string ans(q,'?');
    while(m--){
        FOR(i,q){
            char c, cor; cin >> c >> cor;
            if(cor=='T'){
                ans[i] = c;
            }else{
                gab[i][c-'A'] = 0;
            }
        }
    }
    FOR(i,q){
        if(ans[i]!='?') continue;
        vector<char> pos;
        FOR(j,4){
            if(gab[i][j]) pos.pb(char('A'+j));
        }
        if(sz(pos)==1) ans[i] = pos[0];

    }
    FOR(i,q){
        cout << ans[i] << " \n"[i==q-1];
    }
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
