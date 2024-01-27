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

ll sq( int a, int b){
    return 1LL*(a+b)*(a+b);
}
/* if interactive remove fastio endl */     
/* stop freaking out pls*/ 
void solve(){
    int n; cin >> n;
    vi a(n), b(n);
    FOR(i,n) cin >> a[i];
    FOR(i,n) cin >> b[i];
    vi ca(a), cb(b);

    if(n<2){
        cout << 0 << endl; return;
    }
    int ac = a[n-1], bc = b[n-1];

    auto check = [&](int i){
        int now =  a[i-1]*(a[i]*ac) +  b[i-1]*(b[i]*bc) ;
        int may =  a[i-1]*(b[i]*ac) +  b[i-1]*(a[i]*bc) ;
        return may < now;
    };

    for(int i = n-2; i >=0; --i){
        if(i==0){
            if( ac < bc and a[i] < b[i])
                swap(a[i],b[i]);
            if( ac > bc and a[i] > b[i])
                swap(a[i],b[i]);
        }
        else if(check(i)){
            swap(a[i],b[i]);
        }
        ac += a[i];
        bc += b[i];
    }
    
    ll ans1 = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ans1 += sq(a[i],a[j]) + sq(b[i],b[j]);
        }
    }

    a = ca; b = cb;
    ac = a[n-1], bc = b[n-1];
    for(int i = n-2; i >=0; --i){
        int now = a[i]*ac + b[i]*bc;
        int may = b[i]*ac + a[i]*bc;
        if( may < now) swap(a[i],b[i]);
        ac += a[i];
        bc += b[i];
    }

    ll ans2 = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ans2 += sq(a[i],a[j]) + sq(b[i],b[j]);
        }
    }
    cout << min(ans1,ans2) << endl;
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
