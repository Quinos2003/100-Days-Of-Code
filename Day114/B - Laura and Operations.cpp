// passed 
#include <bits/stdc++.h>
using namespace std;

void tankSize(int a, int b, int c) {
    if (abs(c - b) % 2) {
        cout << "0 ";
    } else {
        cout << "1 ";
    }

    if (abs(a - c) % 2) {
        cout << "0 ";
    } else {
        cout << "1 ";
    }

    if (abs(a - b) % 2) {
        cout << "0 " << endl;
    } else {
        cout << "1 " << endl;
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tankSize(a, b, c);
    }

    return 0;
}
