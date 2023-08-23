
#include<bits/stdc++.h>
using namespace std;

// A Naive recursive C++ program to find minimum of coins
// to make a given change V
// m is size of coins array (number of different coins)

// int minCoins(int coins[], int m, int V)
// {
//    // base case
//    if (V == 0) return 0;
 
//    // Initialize result
//    int res = INT_MAX;
 
//    // Try every coin that has smaller value than V
//    for (int i=0; i<m; i++)
//    {
//      if (coins[i] <= V)
//      {
//          int sub_res = minCoins(coins, m, V-coins[i]);
 
//          // Check for INT_MAX to avoid overflow and see if
//          // result can minimized
//          if (sub_res != INT_MAX && sub_res + 1 < res)
//             res = sub_res + 1;
//      }
//    }
//    return res;
// }


// A Dynamic Programming based C++ program to find minimum
// of coins to make a given change V

// m is size of coins array (number of different coins)
// int minCoins(int coins[], int m, int V)
// {
// 	// table[i] will be storing the minimum number of coins
// 	// required for i value. So table[V] will have result
// 	int table[V + 1];

// 	// Base case (If given value V is 0)
// 	table[0] = 0;

// 	// Initialize all table values as Infinite
// 	for (int i = 1; i <= V; i++)
// 		table[i] = INT_MAX;

// 	// Compute minimum coins required for all
// 	// values from 1 to V
// 	for (int i = 1; i <= V; i++) {
// 		// Go through all coins smaller than i
// 		for (int j = 0; j < m; j++)
// 			if (coins[j] <= i) {
// 				int sub_res = table[i - coins[j]];
// 				if (sub_res != INT_MAX
// 					&& sub_res + 1 < table[i])
// 					table[i] = sub_res + 1;
// 			}
// 	}

// 	if (table[V] == INT_MAX)
// 		return -1;

// 	return table[V];
// }
// Driver program to test above function
// int main()
// {
// 	int coins[] = { 9, 6, 5, 1 };
// 	int m = sizeof(coins) / sizeof(coins[0]);
// 	int V = 11;
// 	cout << "Minimum coins required is "
// 		<< minCoins(coins, m, V);
// 	return 0;
// }

// Coin change using the Top Down (Memoization) Dynamic Programming: 

int minCoinsUtil(int coins[], int m, int V, int* dp)
{
	// Base case: If target value V is 0, no coins are
	// needed
	if (V == 0)
		return 0;

	// If subproblem is already solved, return the result
	// from DP table
	if (dp[V] != -1)
		return dp[V];

	int res = INT_MAX;

	// Iterate over all coins and recursively solve for
	// subproblems
	for (int i = 0; i < m; i++) {
		if (coins[i] <= V) {
			// Recursive call to solve for remaining value V
			// - coins[i]
			int sub_res
				= minCoinsUtil(coins, m, V - coins[i], dp);

			// If the subproblem has a valid solution and
			// the total number of coins is smaller than the
			// current result, update the result
			if (sub_res != INT_MAX && sub_res + 1 < res)
				res = sub_res + 1;
		}
	}

	// Save the result in the DP table
	dp[V] = res;

	return res;
}

// Function to find the minimum number of coins needed to
// make a target value
int minCoins(int coins[], int m, int V)
{
	// Create a DP table to store results of subproblems
	int* dp = new int[V + 1];
	memset(dp, -1,
		sizeof(int)
			* (V + 1)); // Initialize DP table with -1

	// Call the utility function to solve the problem
	return minCoinsUtil(coins, m, V, dp);
}

// Driver code
int main()
{
	int coins[] = { 9, 6, 5, 1 };
	int m = sizeof(coins) / sizeof(coins[0]);
	int V = 11;

	int res = minCoins(coins, m, V);
	if (res == INT_MAX)
		res = -1;

	// Find the minimum number of coins required
	cout << "Minimum coins required is " << res;

	return 0;
}


