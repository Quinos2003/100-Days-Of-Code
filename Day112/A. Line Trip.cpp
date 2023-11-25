
// There is a road, which can be represented as a number line. You are located in the point 0
//  of the number line, and you want to travel from the point 0
//  to the point x
// , and back to the point 0


// You travel by car, which spends 1
//  liter of gasoline per 1
//  unit of distance travelled. When you start at the point 0
// , your car is fully fueled (its gas tank contains the maximum possible amount of fuel).

// There are n
//  gas stations, located in points a1,a2,…,an
// . When you arrive at a gas station, you fully refuel your car. Note that you can refuel only at gas stations, and there are no gas stations in points 0
//  and x


// You have to calculate the minimum possible volume of the gas tank in your car (in liters) that will allow you to travel from the point 0
//  to the point x
//  and back to the point 0

// int tankSize(int x, vector<int>& arr){
//     int tank_size =0;
//     int fuel_left =0;
//     int prev =0;
//     for(int i =0 ; i < arr.size(); i++){
//         fuel_left = fuel_left- arr[i]-prev;

//         if(fuel_left < 0){
//             tank_size += abs(fuel_left);
//             fuel_left = tank_size;
//         }

//         fuel_left= max(fuel_left+1,tank_size);

//         prev = arr[i];
//     }
//     int more_travel = 2*(x - prev);
//     fuel_left = fuel_left - more_travel;
//     if(fuel_left < 0){
//         tank_size += abs(fuel_left);
//     }
//     return tank_size;
// }
#include <bits/stdc++.h>
using namespace std;
int tankSize(int x, vector<int>& arr){
    int tank_size =0;
    int fuel_left =0;
    int prev =0;
    for(int i =0 ; i < arr.size(); i++){
        tank_size= max(tank_size,arr[i]-prev);
        prev = arr[i];
    }
    tank_size = max(tank_size,2*(x-prev));
    
    return tank_size;
}

int main(){
    int t;
    cin>>t;
    vector<int> ans;
    for(int i = 0; i<t; i++){
        int x,n;
        cin>>n>>x;
        vector<int> arr(n);
        for( int ttt =0 ; ttt < n ; ttt++){
            cin>>arr[ttt];
        }
        ans.push_back(tankSize(x,arr));
    }
    for( int i =0 ; i < t ; i ++){
        cout<<ans[i]<<endl;
    }
    return 0;
}