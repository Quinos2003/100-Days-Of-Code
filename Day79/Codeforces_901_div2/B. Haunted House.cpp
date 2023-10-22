#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;

    while (t--) {
        int n;
        string binary;
        cin >> n >> binary;
        vector<int> operations(n, -1);
        int ones_count = 0;
        for (int i = 0; i < n; i++) {

            if (binary[i] == '1')  ones_count++;
            
            for (int j = 0; j < ones_count; j++) {
                if ((i - j + 1) >= (1 << (j + 1))) {
                    operations[j] = i;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << operations[i] << " ";
        }
        cout << endl;
    }
    return 0;
}