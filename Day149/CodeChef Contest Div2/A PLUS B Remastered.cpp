#include <bits/stdc++.h>
using namespace std;

bool canRearrangeToEqualSum(vector<int>& A, vector<int>& B, int N) {
    int sumA = accumulate(A.begin(), A.end(), 0);
    int sumB = accumulate(B.begin(), B.end(), 0);

    if ((sumA + sumB) % N != 0) {
        return false;
    }

    int target = (sumA + sumB) / N;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    for (int i = 0; i < N; i++) {
        if (A[i] + B[i] != target) {
            return false;
        }
    }

    return true;
}

void solve() {
    int n;
    cin >> n;

    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    if (canRearrangeToEqualSum(A, B, n)) {
        for (int x : A) {
            cout << x << " ";
        }
        cout << endl;

        for (int x : B) {
            cout << x << " ";
        }
        cout << endl;
    } else {
        cout << "-1" << endl;
    }
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}
