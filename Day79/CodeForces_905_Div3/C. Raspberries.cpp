#include <bits/stdc++.h>
using namespace std;
int min_operation(vector<int> & arr, int k){
    int operations = k-1;
    if(k==4){
        int count2 = 0;
        int one_less_than_four = 0;
        for( int it : arr){
            if(it%4 ==0) return 0;
            if(it%2==0){
                count2++;
                
            }
            if(it+1%4==0) one_less_than_four++;
        }
        if(count2>=2) return 0;
        else if(count2==1) return 1;
        else if(one_less_than_four>0) return 1;
        else return 2;
    }
    for(int it : arr){
        if(it%k==0) return 0;
        else{
            operations= min (operations, k - it%k);
        }
    }
    return operations;
}


int main(){
    
    int t;
    cin >> t;

    while (t--) {
        int n ,k;
        cin >> n >> k;

        vector<int> arr;
        for(int i =0 ; i < n ; i++){
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }

        int op = min_operation(arr,k);
        cout <<op<< endl;
    }
    return 0;
}