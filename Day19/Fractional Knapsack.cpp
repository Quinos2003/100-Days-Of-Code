//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    
    static bool compare(Item a, Item b) {
        double ratio1 = (double)a.value / a.weight;
        double ratio2 = (double)b.value / b.weight;
        return ratio1 > ratio2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr + n, compare);

        double max_value = 0.0; // Initialize the maximum value in the knapsack.
        double current_weight = 0.0; // Initialize the current weight in the knapsack.

        for (int i = 0; i < n; i++) {
            if (current_weight + arr[i].weight <= W) {
                // If the current item can be completely added to the knapsack, add it.
                current_weight += arr[i].weight;
                max_value += arr[i].value;
            } else {
                // If the current item can only be partially added, add a fraction of it.
                double remaining_space = W - current_weight;
                double fraction = remaining_space / arr[i].weight;
                max_value += (fraction * arr[i].value);
                break; // Knapsack is now full.
            }
        }

        return max_value;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends