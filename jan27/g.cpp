#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i_ , e_ )  for(int i_ = (int) 0 ; i_ <  (int) e_ ; ++i_ )
#define PR( v_ ) for(auto x_ : v_) cout << x_ << " "; cout << endl;
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
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
const int MAX  = 2e4+10;
const int MOD  = 998244354; 

vector<vector<pii>> g;
ll dis[MAX];
void dijkstra(int st){

    priority_queue<pair<ll,int>> pq;
    pq.push({0,st});
    dis[st] = 0;
    while( pq.size() ){
        auto [ndist, u] = pq.top(); pq.pop();
        if( -ndist > dis[u] ) continue;
        for(auto [v,w] : g[u]) if( dis[v] > dis[u] + w){
            dis[v] = dis[u] + w;
            pq.push({-dis[v],v});

        }
    }
}

ll mxDis;
ll len[MAX];

void dijkstra1(int st){

    priority_queue<tuple<ll,ll,int>> pq;
    pq.push({0, 0, st});
    len[st] = 0;
    dis[st] = 0;
    while( pq.size() ){
        auto [nlen, d, u] = pq.top(); pq.pop();

        d = -d;
        for(auto [v,w] : g[u]) {
            if(len[v] == max(w*1LL,len[u]) and (dis[v] > d + w) and (d + w <= mxDis) ){
                len[v] = max(w*1LL,len[u]);
                dis[v] = d + w;
                pq.push({ -len[v], - ( d+ w) , v});
            }
            else if( ( len[v]==0 or len[v] >  max(w*1LL,len[u]) ) and (d + w <= mxDis) ){
                len[v] = max(w*1LL,len[u]);
                dis[v] = d + w;
                pq.push({ -len[v], - (d+ w) , v});
            }

        }
    }
}

/* if interactive remove fastio endl */     
/* stop freaking out pls*/ 
void solve(){
    int n, m, x; cin >> n >> m >> x;
    vector<tuple<int,int,int>> edges1;
    g = vector<vector<pii>>(n);
    FOR(i,m){
        int a,b,w; cin >> a >> b >> w;
        --a; --b;
        g[a].pb({b,w});
        g[b].pb({a,w});
        edges1.emplace_back(w,a,b);
    }
    FOR(i,n) dis[i] = LINF;
    dijkstra(0);

    ll bestDis = dis[n-1];
    ld aux = 1 + ld(x)/100;
    mxDis = ld(bestDis)*aux;

    FOR(i,n) dis[i] = LINF;
    FOR(i,n) len[i] = 0;

    dijkstra1(0);

    cout << len[n-1] << endl;
    cout << dis[n-1] << endl;
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
