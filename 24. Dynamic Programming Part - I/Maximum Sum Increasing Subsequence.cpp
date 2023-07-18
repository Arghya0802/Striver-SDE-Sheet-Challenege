// GFG Link:  https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
// -------------------------------------------------------------------------------------------------

#include <bits/stdc++.h> 

int maxIncreasingSum(int ind , int prevIndex , vector<int> &rack , vector<vector<int>> &dp)
{
	if(ind >= rack.size() )   return 0 ;

	if(dp[ind][prevIndex + 1] != -1)  return dp[ind][prevIndex + 1] ;

	int skip = maxIncreasingSum(ind + 1 , prevIndex , rack , dp) ;  int pick = 0 ;

	if(prevIndex == -1 || rack[ind] > rack[prevIndex] )
		pick = rack[ind] + maxIncreasingSum(ind + 1 , ind , rack , dp) ;

	return dp[ind][prevIndex + 1] = max(pick , skip) ;
}

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	vector<vector<int>> dp(n + 1 , vector<int> (n + 1 , -1) ) ;

	return maxIncreasingSum(0 , -1 , rack , dp) ;
}

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N ^ 2)
