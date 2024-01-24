#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(1) {
        int n, k, m;
        cin >> n >> k >> m;
        if(n == -1 && k == -1 && m == -1) {
            break;
        }
        vector<int> porta(n), chave(n, -1);
        for(int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            porta[b] = 1;
            chave[a] = b;
        }
        vector<vector<int>> g(n);
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        set<int> espera, tem_chave;
        vector<bool> vis(n);
        function<void(int)> dfs = [&](int u) {
            vis[u] = 1;
            porta[u] = 0; chave[u] = -1;
            for(auto nxt : g[u]) {
                if(porta[nxt]) {
                    if(tem_chave.count(nxt)) {
                        tem_chave.erase(nxt);
                        dfs(nxt);
                    } else {
                        espera.insert(nxt);
                    }
                }
                if(chave[nxt] != -1) {
                    if(espera.count(chave[nxt])) {
                        espera.erase(chave[nxt]);
                        dfs(chave[nxt]);
                    } else {
                      tem_chave.insert(chave[nxt]);
                    }
                }
                if(!vis[nxt] && !porta[nxt]) {
                    dfs(nxt);
                }
            }
        };
        dfs(0);
        cout << (vis[n - 1] ? "Y" : "N") << '\n';
    }
    return 0;
 }
