#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n), rg(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    vector<bool> vis(n);
    stack<int> stk;
    function<void(int)> dfs1 = [&](int u) {
        vis[u] = true;
        for(auto nxt : g[u]) {
            if(!vis[nxt]) {
                dfs1(nxt);
            }
        }
        //cout << u << '\n';
        stk.push(u);
    };
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs1(i);
        }
    }
    vis = vector<bool> (n);
    vector<int> comp(n);
    int c = 0;
    function<void(int)> dfs2 = [&](int u) {
        vis[u] = true;
        comp[u] = c;
        for(auto nxt : rg[u]) {
            if(!vis[nxt]) {
                dfs2(nxt);
            }
        }
    };
 //  cout << "----------\n";
    while(!stk.empty()) {
        int u = stk.top(); stk.pop();
    //    cout << u << '\n';
        if(vis[u]) continue;
        dfs2(u);
        c++;
    }
    vector<vector<int>> adj(n);
    vector<int> degree(n);
    for(int i = 0; i < n; i++) {
        for(auto x : g[i]) {
            if(comp[i] != comp[x]) {
                adj[comp[x]].push_back(comp[i]);
                degree[comp[i]] += 1;
            }
        }
    }
    vis = vector<bool> (n);
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        for(auto nxt : adj[u]) {
            if(!vis[nxt]) {
                dfs(nxt);
            }
        }
    };
    dfs(c - 1);
    bool ok = 1;
    int cnt = 0;
    for(int i = 0; i < c; i++) {
        ok &= vis[i];
        if(degree[i] == 0) {
            cnt += 1;
        }
    }
    ok &= (cnt <= 1);
    if(!ok) {
        cout << 0 << '\n';
    } else {
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(comp[i] == c - 1) {
                ans.push_back(i + 1);
            }
        }
        cout << (int) ans.size() << '\n';
        for(auto x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
 }
