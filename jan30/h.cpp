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
const ll MOD  = 998244353; 
 
class HashedString {

  private:

	// change M and B if you want

	static const long long M = (1LL << 61) - 1;

	static const long long B;


	// pow[i] contains B^i % M

	static vector<long long> pow;


	// p_hash[i] is the hash of the first i characters of the given string

	vector<long long> p_hash;


  public:

	HashedString(const string &s) : p_hash(s.size() + 1) {

		while (pow.size() < s.size()) { pow.push_back((pow.back() * B) % M); }


		p_hash[0] = 0;

		for (int i = 0; i < s.size(); i++) {

			p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;

		}

	}


	long long get_hash(int start, int end) {

		long long raw_val =

		    (p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]));

		return (raw_val % M + M) % M;

	}

};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
vector<long long> HashedString::pow = {1};
const ll HashedString::B = uniform_int_distribution<ll>(0, M - 1)(rng);


void solve(){
    string s; cin >> s;
    HashedString hs(s);
    int q; cin >> q;
    
    while( q-- ){
        int l,r; cin >> l >> r;
        // l--; r--;
        cout << hs.get_hash(l , r-1) << endl;
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
