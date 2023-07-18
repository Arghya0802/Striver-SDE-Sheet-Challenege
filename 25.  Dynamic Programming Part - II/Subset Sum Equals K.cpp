// LeetCode Link:  https://leetcode.com/problems/partition-equal-subset-sum/
// -------------------------------------------------------------------------

#include <bits/stdc++.h> 

bool SubsetSumEqualsK(int ind , int k , vector<int> &nums , vector<vector<int>> &dp)
{
    if(k == 0)  return true ;
    
    if(ind >= nums.size() )  return false ;

    if(dp[ind][k] != -1)  return dp[ind][k] ;
    
    bool skip = SubsetSumEqualsK(ind + 1 , k , nums , dp) ;

    if(skip == true)  return dp[ind][k] = true ;

    if(nums[ind] <= k)
    {
        bool pick = SubsetSumEqualsK(ind + 1 , k - nums[ind] , nums , dp) ;

        if(pick)  return dp[ind][k] = true ;
    }

    return dp[ind][k] = false ;
}

bool subsetSumToK(int n, int k, vector<int> &arr) 
{
    vector<vector<int>> dp(n + 1,  vector<int> (k + 1 , -1) ) ;

    return SubsetSumEqualsK(0 , k , arr , dp) ;
}

// Time Complexity:  O(N * K)
// Space Complextiy: O(N * K)
