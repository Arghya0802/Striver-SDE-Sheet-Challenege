// GFG Link:  https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// ----------------------------------------------------------------------------------

#include <bits/stdc++.h>

int maxProfit(int ind , int target , vector<int> &weights , vector<int> &profits , vector<vector<int>> &dp)
{
	if(target == 0)  return 0 ;

	if(ind >= weights.size() )  return 0 ;

	if(dp[ind][target] != -1)  return dp[ind][target] ;

	int skip = maxProfit(ind + 1 , target , weights , profits , dp) ; 
	int pick = 0 ;

	if(weights[ind] <= target)  
		pick = profits[ind] + maxProfit(ind + 1 , target - weights[ind] , weights , profits , dp) ;

	return dp[ind][target] = max(skip , pick) ;
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n + 1 , vector<int> (w + 1 , -1) ) ;

	return maxProfit(0 , w , weights , values , dp) ;
}

// Time Complexity:  O(N * Target)
// Space Complexity: O(N * Target)
