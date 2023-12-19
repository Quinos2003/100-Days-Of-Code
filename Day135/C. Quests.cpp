#include <bits/stdc++.h>
using namespace std;
int main() {
    int ttt;
    cin >> ttt;

    while (ttt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int exp = 0, max_exp = 0, max_sub_exp = 0;

        for (int curr_q = 0; curr_q < n; curr_q++) {
            if (k == curr_q) {
                break;
            }

            exp += a[curr_q];
            max_sub_exp = max(max_sub_exp, b[curr_q]);
            max_exp = max(exp + (k - curr_q - 1) * max_sub_exp, max_exp);
        }

        cout << max_exp <<endl;
    }

    return 0;
}