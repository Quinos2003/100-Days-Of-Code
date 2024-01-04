#include <bits/stdc++.h>
using namespace std;

void solve(long long int n, long long int x) {
    if (x == 0) {
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    if (n - x <= 1) {
        cout << "-1\n";
        return;
    }

    long long int startingValue = n - 1 - x;
    x = n + 1 - startingValue;

    cout << x << " ";

    int currentValue = 1;

    for (int i = 1; i < n; i++) {
        if (i == x) {
            currentValue++;
        }
        cout << currentValue << " ";
        currentValue++;
    }

    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t > 0) {
        t--;
        long long int n, x;
        cin >> n >> x;
        solve(n, x);
    }

    return 0;
}
