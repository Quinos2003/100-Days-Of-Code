#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n == 1) return false;
    if (n == 2) return true;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

int main(){
    int t;
    cin >> t;

    while (t--) {
        int n;
        vector<int> arr(n, -1) ;
        cin >> n;
        for(int i =0 ; i < n ; i++){
            cin>>arr[i];
        }
        vector<int> prime;
        // if is prime then add them to another array
        for(int i =0 ; i < n ; i++){
            if(isPrime(arr[i])){
                prime.push_back(arr[i]);
            }
        }
        // sort the prime array
        sort(prime.begin(),prime.end());

        // You are given an array of integers a1,a2,…,an
        // A pair of integers (i,j), such that 1≤i<j≤n, is called good, if there does not exist an integer k
        //  (1≤k≤n) such that ai is divisible by ak and aj is divisible by ak at the same time.

        // You have to find the number of good pairs in the given array.
        //  Formally, you have to find the number of pairs (i,j) such that 1≤i<j≤n and (ai,aj) is a good pair.
        //  Note that pairs (i,j) and (j,i) are considered different if i≠j.
        //  For example, if n=3 and a=[6,2,3], then there are 3 good pairs: (1,2), (1,3) and (2,3).

        // 1. find the prime numbers in the array
        // 2. sort the prime numbers
        // 3. find the number of good pairs
        // 4. print the number of good pairs
        int good_pairs = 0;
        for(int i =0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                if(arr[i]!=-1 && arr[j]!=-1){
                    if(__gcd(arr[i],arr[j])==1){
                        good_pairs++;
                    }
                }
            }
        }
        cout << good_pairs << endl;

    }
    return 0;
}