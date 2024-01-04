#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int idx = 0, mn = v[0];
    int ans = 0;
    vector<int> v1(n);
    v1[0] = v[0];

    for (int i = 0; i < n; i++) {
        if (v[i] <= mn) {
            mn = v[i];
            idx = i;
        }
        if (v[i] > 0) {
            ans++;
        }
        if (i > 0) {
            v1[i] = min(v1[i - 1], v[i]);
        }
    }

    int cnt = 0;
    int res = ans;

    for (int i = idx; i >= 0; i--) {
        if (v[i] == v1[i] && v[i] > 0) {
            cnt++;
            int oper = v[i];
            res = min(res, ans - cnt + oper);
        }
    }

    cout << res << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
