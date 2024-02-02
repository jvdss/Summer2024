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
string treat( string& s){
    string pt = "";
    for(int i = 0; i < sz(s); i++){
        if(s[i]== '(' or s[i]== ')'){
            pt += ' '; pt+= s[i]; pt += ' ';
        }else if(s[i] != ' '){
            pt += s[i];
        }
    }
    return pt ;
}
void solve(){
    auto get_t = [](string& ss, vi&par){
        istringstream iss(ss);
        stack<int> parents;

        while( iss >> ss){
            if(ss[0] == '(' ){
                continue;
            }else if( ss[0] == ')'){
                parents.pop();
                continue;
            }
            int id = stoi(ss);
            if( parents.size() == 0) par[id] = id;
            else par[id] = parents.top();
            parents.push(id);
        }
    };
    string s; 
    getline(cin,s); s = treat(s);
    vi p1(1e6+1 , -1);
    get_t( s, p1);

    getline(cin,s); s = treat(s);
    vi p2(1e6+1 , -1);
    get_t( s, p2);
    bool ok = true;

    for(int i = 0; i < (int) p1.size() ; i++ ){
        if( p1[i] == p2[i] and p1[i] == -1 ) continue;
        if( p1[i] > 0 and p2[i] > 0){
            ok &= (p1[i]==p2[i]) ;
        }else{
            ok = false;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
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
