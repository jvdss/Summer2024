#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 5e5 + 5;

vector<int> grafo[MAXN];
vector<int> aresta[MAXN];
int marc[MAXN], in[MAXN], out[MAXN], pre[MAXN], low[MAXN], componenteDaAresta[MAXN], pilhaAresta[MAXN], pontoDeArticulacao[MAXN];
int t, c, p, TIMER;
int vertices_da_componente[MAXN];
int marcAresta[MAXN], marcComp[MAXN];


void novaComponenteBiconexa(int idAresta) {
    c++;
    int a;
    do {
        a = pilhaAresta[p];
        p--;
        componenteDaAresta[a] = c;
        if(p == -1) break;
    } while(a != idAresta);
}

void dfs(int v, int pai) {
    t++;
    pre[v] = t;
    low[v] = t;
    marc[v] = 1;
    int qtdFilhos = 0;
    for(int i = 0; i < grafo[v].size(); i++) {
        int viz = grafo[v][i];
        int idAresta = aresta[v][i];

        if(marcAresta[idAresta] == 1) continue;
        marcAresta[idAresta] = 1;
        p++;
        pilhaAresta[p] = idAresta;

        if(marc[viz] == 0) {
            qtdFilhos++;
            dfs(viz, v);
            low[v] = min(low[v], low[viz]);

            bool achouNovaComponente = false;
            if(v == 1 && qtdFilhos >= 2) achouNovaComponente = true;
            if(v != 1 && low[viz] >= pre[v]) achouNovaComponente = true;

            if(achouNovaComponente) {
                pontoDeArticulacao[v] = 1;
                novaComponenteBiconexa(idAresta);
            }
        } else {
            low[v] = min(low[v], pre[viz]);
        }
    }
}

signed main() {
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
        aresta[v].push_back(i);
        aresta[u].push_back(i);
    }
    t = 0, p = -1, c = 0;
    dfs(1, 0);
    novaComponenteBiconexa(-1);
    vector<vector<int>> blockCutTree(MAXN);

    for(int i = 1; i <= n; i++) {
        if(pontoDeArticulacao[i] != 1) continue;

        c++;
        pontoDeArticulacao[i] = c;
        for(int j = 0; j < aresta[i].size(); j++) {
            int idAresta = aresta[i][j];
            int comp = componenteDaAresta[idAresta];
            if(marcComp[comp] == 0) {
                marcComp[comp] = 1;
                blockCutTree[pontoDeArticulacao[i]].push_back(comp);
                blockCutTree[comp].push_back(pontoDeArticulacao[i]);
            }
        }

        for(int j = 0; j < aresta[i].size(); j++) {
            int idAresta = aresta[i][j];
            int comp = componenteDaAresta[idAresta];
            marcComp[comp] = 0;
        }
    }
    vector<pair<int, int>> edge;
    function<void(int, int)> build = [&](int u, int p) {
        in[u] = TIMER++;
        for(auto nxt : blockCutTree[u]) {
            if(nxt != p) {
                edge.emplace_back(u, nxt);
                build(nxt, u);
            }
        }
        out[u] = TIMER++;
    };
    build(1, 0);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < aresta[i].size(); j++) {
            int idAresta = aresta[i][j];
            int comp = componenteDaAresta[idAresta];
            vertices_da_componente[i] = comp;
            vertices_da_componente[grafo[i][j]] = comp;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(pontoDeArticulacao[i]) {
            vertices_da_componente[i] = pontoDeArticulacao[i];
        }
    }
    while(q--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(b == c) {
            cout << "NO\n";
        } else if(a == b) {
            cout << "YES\n";
        } else if(pontoDeArticulacao[c] == 0) {
            cout << "YES\n";
        } else {
            
            a = vertices_da_componente[a], b = vertices_da_componente[b], c = vertices_da_componente[c];
           cout << "queries: " << a << ' ' << b << ' ' << c << '\n';
            if(in[a] >= in[c] && out[a] <= out[c] && in[b] >= in[c] && out[b] <= out[c]) {
                cout << "YES\n";
            } else if((in[a] >= in[c] && out[a] <= out[c]) || (in[b] >= in[c] && out[b] <= out[c])) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
    cout << "------------\n";
    for(auto [a, b] : edge) {
        cout << a << ' ' << b << '\n';
    }
    cout << "--------\n";
    for(int i = 1; i <= n; i++) {
        cout << i << ' ' << vertices_da_componente[i] << '\n';
    }
}
