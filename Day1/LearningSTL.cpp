#include<iostream>
#include<array>
#include<vector>
using namespace std;
int main(){

    cout<<"hello "<<endl;
    int  basic [3] = {1,2,3};

    array<int,4> arr = {5,6,7,8};

    int len = arr.size();

    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<endl;
    }

    cout<<"----------------------------------------------------------------------------------"<<endl;


    cout<<"hello "<<endl;

    cout<<"ELEMENT AT INDEX 2 is  "<<arr.at(2)<<endl;

    cout<<"CHECK EMPTY "<<arr.empty()<<endl;
    cout<<"first element "<<arr.front()<<endl;
    cout<<"last element "<<arr.back()<<endl;
    cout<<"----------------------------------------------------------------------------------"<<endl;


    vector<int> v ;
    
    v.push_back(1);
    v.push_back(2);
    // adding extra elemts doubles the capacity of array each time it is exceeded 
    cout<<"----------------------------------------------------------------------------------"<<endl;


    vector<int> a(5,1);
    int n = a.size();
    cout<<"Initialising an array with desired filled values "<<endl;

    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"----------------------------------------------------------------------------------"<<endl;
    cout<<"COPYING VECTOR "<<endl;

    vector<int> anew(a);
    for (int i = 0; i < n; i++)
    {
        cout<<anew[i]<<" ";
    }



    cout<<""<<endl;
    cout<<""<<endl;



    
}