#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin >> t;

    while (t--) {
        string pin;
        cin >> pin;

        int time = 0;
        char prev = '1';

        for (int i = 0; i < 4; i++) {
            if(pin[i]=='0'){
                time = time + ('9'- prev)+1;
                prev = '9'+1;
            }
            else {
                time += abs(pin[i] - prev);
                prev = pin[i];
            }
            time++;
        }
        cout <<time << endl;
    }
    return 0;
}