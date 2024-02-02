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

ld cross(ld x1, ld y1, ld x2, ld y2)
{return x1*y2-x2*y1;}

ld polygonArea(vector<pair<ll,ll>>&A)
{
    ld ats = 0.0;
    for(int i=2; i<A.size(); i++)
        ats+=cross(A[i].first-A[0].first,A[i].second-A[0].second,A[i-1].first-A[0].first,A[i-1].second-A[0].second);
    return abs(ats/2);
}

ll boundary(vector<pair<ll,ll>>&A)
{
    ll ats = A.size();
    for(int i=0; i<A.size(); i++)
    {
        ll dx = (A[i].first - A[(i+1)%A.size()].first);
        ll dy = (A[i].second - A[(i+1)%A.size()].second);
        ats+=abs(__gcd(dx,dy)) - 1;
    }
    return ats;
}

void solve(){
    int n; cin >> n;
    vector<pair<ll,ll>> points(n);
    for(auto&[a,b] : points){
        cin >> a >> b;
    }
    ll a = polygonArea(points);
    ll b = boundary(points);
    ll c = a + 1 - b/2;
    cout << c << " " << b << endl;
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
