// s.contains("0");
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    for(int i = 0; i<t; i++){
        int n, p, L, t;
        cin >> n >> p >> L >> t;

        int left_bound = 0;
        int right_bound = n;

        while (right_bound - left_bound > 1){
            int mid = (right_bound + left_bound) / 2;
            int total_time = mid * L;
            int extra_time = min(mid * 2, (n + 6) / 7) * t;
            total_time += extra_time;

                    if (total_time < p)
            left_bound = mid;
        else
            right_bound = mid;
        }
        cout << n-right_bound << endl;

    }
    return 0;
}