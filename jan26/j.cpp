#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e9;
int n, m;
int M[112][112][4];
int memo[10 * 200][10 * 200];

int dp(int i, int j, int a, int b) {
    if(i >= n || j >= m) return -inf;
    if(i == n - 1 && j == m - 1) return min(a + M[i][j][2], b + M[i][j][3]);
    int& p = memo[a][b];
    if(p != -1) {
        return p;
    }
    return p = max(dp(i + 1, j, a + M[i][j][2], b + M[i][j][3]), dp(i, j + 1, a + M[i][j][2], b + M[i][j][3]));
}

signed main() {
    int tt;
    cin >> tt;
    while(tt--) {
        cin >> n >> m;
        for(int l = 0; l < 10 * 200; l++) {
            for(int k = 0; k < 10 * 200; k++) {
                memo[l][k] = -1;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int x;
                cin >> x;
                for(int k = 2; k <= 3; k++) {
                    while(x % k == 0) {
                        x /= k;
                        M[i][j][k] += 1;
                    }
                }
            }
        }
        cout << dp(0, 0, 0, 0) << '\n';
    }
}
