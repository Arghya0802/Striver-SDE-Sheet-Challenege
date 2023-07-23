// GFG Link:  https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
// -----------------------------------------------------------------------------------------

#include <bits/stdc++.h> 

int MCM(int start , int end , vector<int> &arr , vector<vector<int>> &dp)
{
    if(start == end - 1)  return dp[start][end] = 0 ;

    if(dp[start][end] != -1)  return dp[start][end] ;

    int ans = INT_MAX ;

    for(int i = start + 1 ; i < end ; i++)
    {
        if(dp[start][i] == -1)  dp[start][i] = MCM(start , i , arr , dp) ;

        if(dp[i][end] == -1)  dp[end][i] = MCM(i , end , arr , dp) ;

        int currAns = dp[start][i] + dp[i][end] + (arr[start] * arr[i] * arr[end] ) ;

        ans = min(ans , currAns) ;
    }

    return dp[start][end] = ans ;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N + 1 , vector<int> (N + 1 , -1) ) ;

    return MCM(0 , N - 1 , arr , dp) ;
}

// Time Complexity:  O(N ^ 3)
// Space Complexity: O(N ^ 2) [2D DP]
