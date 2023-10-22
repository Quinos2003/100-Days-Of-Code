#include <bits/stdc++.h>
using namespace std;
int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int findSmallestKBeautiful(int x, int k) {
    while (true) {
        int sum = digitSum(x);
        if (sum % k == 0) {
            return x;
        }
        x++;
    }
}

int main(){
    // int t;
    // cin>>t;
    // for (int i = 0; i < t; i++)
    // {
    //     int x,k;
    //     cin>>x>>k;
    //     int sum_of_x=0;
    //     int num =x;
    //     while (num>0)
    //     {
    //         sum_of_x+=num%10;
    //         num/=10;
    //     }
        
    //     if(sum_of_x%k==0){
    //         cout<<x<<endl;
    //     }
    //     else{
    //         int add = k - sum_of_x%k;

    //         if(x+add%k==0) cout<<x+add<<endl;
    //         else {

    //         }

            
    //     }
    // }
    int t;
    cin >> t;

    while (t--) {
        int x, k;
        cin >> x >> k;
        cout << findSmallestKBeautiful(x, k)<< endl;
    }
    return 0;
}