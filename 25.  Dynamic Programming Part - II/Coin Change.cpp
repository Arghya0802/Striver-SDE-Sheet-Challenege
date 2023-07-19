// LeetCode Link:  https://leetcode.com/problems/coin-change/
// ---------------------------------------------------------

#include <bits/stdc++.h>
using ll = long long int ;

ll totalWays(int ind , int n , int target , int coins[] , vector<vector<ll>> &dp)
{
    if(target == 0)  return 1 ;

    if(ind >= n)     return 0 ;

    if(dp[ind][target] != -1)  return dp[ind][target] ;
    
    ll skip = totalWays(ind + 1,  n , target , coins , dp) ;  ll pick = 0 ;
    
    if(coins[ind] <= target)
        pick = totalWays(ind , n , target - coins[ind] , coins , dp) ;

    return dp[ind][target] = (skip + pick) ;
}

long countWaysToMakeChange(int denominations[] , int n, int value)
{
    vector<vector<ll>> dp(n + 1 , vector<ll> (value + 1 , -1) ) ;

    return totalWays(0 , n , value , denominations , dp) ;
}

// Time Complexity:  O(N * Amount)
// Space Complexity: O(N * Amount)
