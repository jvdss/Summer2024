#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    sum /= n;
    int ans = 0;
    for(int i = 0; i < n && a[i] < sum; i++) {
        ans += abs(a[i] - sum);
    }
    cout << ans << '\n';

    return 0;
}
