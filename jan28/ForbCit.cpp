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
const int MAX  = 1e5 +30;
const int MOD  = 998244354; 
 
// Block-Cut Tree
//
// Cria a block-cut tree, uma arvore com os blocos
// e os pontos de articulacao
// Blocos sao componentes 2-vertice-conexos maximais
// Uma 2-coloracao da arvore eh tal que uma cor sao
// os blocos, e a outra cor sao os pontos de art.
// Funciona para grafo nao conexo
//
// art[i] responde o numero de novas componentes conexas
// criadas apos a remocao de i do grafo g
// Se art[i] >= 1, i eh ponto de articulacao
// 
// Para todo i <= blocks.size()
// blocks[i] eh uma componente 2-vertce-conexa maximal
// edgblocks[i] sao as arestas do bloco i
// tree[i] eh um vertice da arvore que corresponde ao bloco i
// 
// pos[i] responde a qual vertice da arvore vertice i pertence
// Arvore tem no maximo 2n vertices
//
// O(n+m)

vector<vector<int>> biconnected_components(vector<vector<int>> &g,

                                           vector<bool> &is_cutpoint,

                                           vector<int> &id) {

	int n = (int)g.size();


	vector<vector<int>> comps;

	vector<int> stk;

	vector<int> num(n);

	vector<int> low(n);


	is_cutpoint.resize(n);


	// Finds the biconnected components

	function<void(int, int, int &)> dfs = [&](int node, int parent,

	                                          int &timer) {

		num[node] = low[node] = ++timer;

		stk.push_back(node);

		for (int son : g[node]) {

			if (son == parent) { continue; }

			if (num[son]) {

				low[node] = min(low[node], num[son]);

			} else {

				dfs(son, node, timer);

				low[node] = min(low[node], low[son]);

				if (low[son] >= num[node]) {

					is_cutpoint[node] = (num[node] > 1 || num[son] > 2);

					comps.push_back({node});

					while (comps.back().back() != son) {

						comps.back().push_back(stk.back());

						stk.pop_back();

					}

				}

			}

		}

	};


	int timer = 0;

	dfs(0, -1, timer);

	id.resize(n);


	// Build the block-cut tree

	function<vector<vector<int>>()> build_tree = [&]() {

		vector<vector<int>> t(1);

		int node_id = 0;

		for (int node = 0; node < n; node++) {

			if (is_cutpoint[node]) {

				id[node] = node_id++;

				t.push_back({});

			}

		}


		for (auto &comp : comps) {

			int node = node_id++;

			t.push_back({});

			for (int u : comp)

				if (!is_cutpoint[u]) {

					id[u] = node;

				} else {

					t[node].push_back(id[u]);

					t[id[u]].push_back(node);

				}

		}

		return t;

	};


	return build_tree();

}

vector<vi> g;
int t;
const int LOG = 20;
int up[MAX][LOG], depth[MAX];
int pre[MAX], pos[MAX];
int last;
int par[MAX];
void dfs(int u,int p = -1){
    // pre[u] = t++;
    // up[u][0] = p;
    // if( p == -1) up[u][0] = u;
    last = u;
    // for(int i = 1 ; i < LOG; ++i){
    //     up[u][i] = up[ up[u][i-1] ][i-1];
    // }
    
    for(auto v : g[u]){
        if( v==p ) continue;
        // depth[v] = depth[u] + 1;
        par[v] = u;
        dfs(v,u);
    }
    // pos[u] = t++;
    
}

int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a,b);
 
    // encontra o kth ancestral de a t.q. depth[a] == depth[b]
    int k = depth[a] - depth[b];
    for(int j = 0; j < LOG; ++j) if( k & ( 1 << j ) )
        a = up[a][j];
        
    if(a==b) return a;
 
    for(int j = LOG-1; j>=0; --j )
        if( up[a][j] != up[b][j])
            a = up[a][j], b = up[b][j];
        
    return up[a][0];
}
 
bool check_sub( int x, int z){
    cout << "Checking " << x << " " << z << endl;
    cout << pre[x] << " " << pos[x] << endl;
    cout << pre[z] << " " << pos[z] << endl;
    cout << lca(x,z) << endl ;
    if( pre[z] <= pre[x] and pos[x] <= pos[z]){
        return lca(x,z) == z;
    }
    return false;
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m,q; cin >> n >> m >> q;
    vector<vector<int>> ng(n);
    vector<tuple< int, int, int >> arestas;
    FOR(i,m){
        int u,v; cin >> u >> v;
        --u; --v;
       ng[v].pb(u); ng[u].pb(v);
       arestas.push_back({u,v, i});
    }
    
    vector<bool> iscut(n);
    vi id(n);
    g = biconnected_components( ng, iscut, id);
    t = 0;
    int root = 0;

    for( int i = 0; i < g.size(); ++i){
        if( g[i].size() == 1) root = i;
    }
    par[root] = root;
    dfs(root,-1);
    vi path;
    
    while(par[last] != last){
        path.pb(last);
        last = par[last] ;
    }

    path.pb(root);
    reverse(all(path));
    for(auto x : path){
        cout << x+1 << " ";
    }
    cout << endl;

    for(auto x : path){
        cout << (iscut[x]) << " ";
    }
    cout << endl;
    // while ( q-- ){
    //     int a,b,c; cin >> a >> b >> c;
    //     --a; --b; --c;
    //     if( a == b or bcut.art[c] ==0 ){ cout << "YES\n"; continue; }
    //     if( a == c or c == b){ cout << "NO\n"; continue ;}
    //     int compa = bcut.pos[a];
    //     int compb = bcut.pos[b];
    //     int compc = bcut.pos[c];
    //     // if( compa == compb){ cout << "YES\n"; continue; }
        
    //     if( lca(compa,compb) == compc) { cout << "NO\n"; continue ;}
    //     cout << a+1 << " " << compa << "\n";
    //     cout << b+1 << " " << compb << "\n";
    //     cout << c+1 << " " << compc << "\n";
    //     int ispos = 0;
    //     if( check_sub(compa, compc)) ispos++;
    //     if( check_sub(compb, compc)) ispos++;

    //     cout << ispos << endl;
    //     if ( ispos == 0){ cout << "YES\n"; continue; }
    //     else { cout << "NO\n"; continue; }
    // }

}