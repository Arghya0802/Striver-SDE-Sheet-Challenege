// LeetCode Link: 
// -----------------------------------------------------------

/* Approach:
1. Simple recursion to find out the Total Number of ways by moving right and down
2. We need to memoize the our code using DP
*/

#include <bits/stdc++.h> 

int totalUniqueWays(int currRow , int currCol , int m , int n , vector<vector<int>> &dp)
{
	if(currRow >= m || currCol >= n)  return 0 ;

	if(currRow == m - 1 && currCol == n - 1)  return 1 ;

	if(dp[currRow][currCol] != -1)  return dp[currRow][currCol] ;

	int right = totalUniqueWays(currRow , currCol + 1 , m , n , dp) ;

	int down  = totalUniqueWays(currRow + 1 , currCol , m , n , dp) ;

	return dp[currRow][currCol] = (right + down) ;
}

int uniquePaths(int m, int n) 
{
	vector<vector<int>> dp(m + 1 , vector<int> (n + 1 , -1) ) ;

	return totalUniqueWays(0 , 0 , m , n , dp) ;
}

// Time Complexity:  O(M * N)
// Space Complexity: O(M * N)
