#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,x,y;
    cin >> n>>x>>y;
    int count =0;
    
    if(n>x){
        std::cout << "NO" << std::endl;
        return;
    }
    else{
        y=y/3;
        x=x-y;
        count = y+x/2;
        if(count>=n){
            cout<<"YES"<<endl;
        }
        else std::cout << "NO" << std::endl;
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

// INPUT 
// 5
// 4 6 6
// 4 6 5
// 5 4 21
// 3 6 1
// 5 6 12

// OUTPUT 
// YES
// NO
// NO
// YES
// YES