// LeetCode Link:  https://leetcode.com/problems/minimum-path-sum/
// ---------------------------------------------------------------

#include <bits/stdc++.h> 

int minPathSum(int row , int col , vector<vector<int>> &grid , vector<vector<int>> &dp)
{
    if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() )  return 1e8 ;

    if(row == grid.size() - 1 && col == grid[0].size() - 1)  return grid[row][col] ;

    if(dp[row][col] != -1)  return dp[row][col] ;

    int right = minPathSum(row , col + 1 , grid , dp) + grid[row][col] ;

    int down = minPathSum(row + 1 , col , grid , dp)  + grid[row][col] ;

    return dp[row][col] = min(right , down) ;
}

int minSumPath(vector<vector<int>> &grid) 
{
    int m = grid.size() ; int n = grid[0].size() ;

    vector<vector<int>> dp(m + 1 , vector<int> (n + 1 , -1) ) ;

    return minPathSum(0 , 0 , grid , dp) ;
}

// Time Complexity:  O(M * N)
// Space Complexity: O(M * N)
