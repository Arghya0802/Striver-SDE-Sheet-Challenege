// LeetCode Link:  https://leetcode.com/problems/longest-increasing-subsequence/
// -----------------------------------------------------------------------------

#include <bits/stdc++.h>

int LIS(int ind , int prevIndex , int n , int arr[] , vector<vector<int>> &dp)
{
    if(ind >= n)  return 0 ;

    if(dp[ind][prevIndex + 1] != -1)  return dp[ind][prevIndex + 1] ;
    
    int skip = LIS(ind + 1 , prevIndex , n , arr , dp) ;  int pick = 0 ;

    if(prevIndex == -1 || arr[ind] > arr[prevIndex] ) 
        pick = 1 + LIS(ind + 1 , ind , n , arr , dp) ;

    return dp[ind][prevIndex + 1] = max(pick , skip) ;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp ;  dp.push_back(arr[0] );

    for( int i = 1 ; i < n ; i++ ) 
    {

        int ind = lower_bound( dp.begin() , dp.end() , arr[i] ) - dp.begin();

        if( ind == dp.size())  dp.push_back(arr[i]) ;

        else  dp[ind] = arr[i] ;

    }

    return dp.size() ;

}

// Time Complexity:  O(N * Log N)
// Space Complexity: O(N)
