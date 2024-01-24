#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5;

vector<vector<int>> g, grafo;
int marc[MAXN], pre[MAXN], low[MAXN];
int t;
vector<int> id, sz;

int find(int x) {
  return id[x] = (id[x] == x ? x : find(id[x]));
}

void uni(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return;
    if(sz[x] > sz[y]) swap(x,y);
    id[x] = y;
    sz[y] += sz[x];
}

void dfs(int v, int pai) {
    t++;
    pre[v] = t;
    low[v] = t;
    marc[v] = 1;
    for(int i = 0; i < grafo[v].size(); i++) {
        int viz = grafo[v][i];
        if(marc[viz] == 0) {
            dfs(viz, v);
            low[v] = min(low[v], low[viz]);
        } else {
            if(viz == pai) continue;

            low[v] = min(low[v], pre[viz]);
        }
    }
    if(v != 1 && low[v] == pre[v]) {
        uni(v, pai);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(1) {
        int n, m, q;
        cin >> n >> m >> q;
        if(!n && !m && !q) break;
        t = 0;
        sz = vector<int> (n + 1, 1);
        id = vector<int> (n + 1);
        iota(id.begin(), id.end(), 0);
        grafo = g = vector<vector<int>> (n + 1);
        for(int i = 1; i <= n; i++) {
            marc[i] = pre[i] = low[i] = 0;
        }
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            grafo[u].push_back(v);
            grafo[v].push_back(u);
        }
        dfs(1, 0);
        while(q--) {
            int a, b;
            cin >> a >> b;
            cout << (find(a) == find(b) ? "Y" : "N") << '\n';
        }
        cout << "-\n";
    }
    return 0;
 }
