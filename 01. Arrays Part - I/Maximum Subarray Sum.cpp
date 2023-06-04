// LeetCode Link:  https://leetcode.com/problems/maximum-subarray/
// ----------------------------------------------------------------

// Approach:
// The Algorithm works on the intuition that we discard any subarray whose sum is negative because including any such subarray would only decrease our Maximum SubArray Sum. 
// We try to be greedy, and store the max(currSum , maxSum) into our maxSum always

// -------------------------------------------------------------------

#include <bits/stdc++.h> 
using ll = long long int ;

long long maxSubarraySum(int arr[], int n)
{
    ll maxSum = 0 ;  ll currSum = 0 ;

    for(int i = 0 ; i < n ; i++)
    {
        currSum += arr[i] ;

        if(maxSum < currSum)  maxSum = currSum ;

        if(currSum < 0)  currSum = 0 ;
    }

    return maxSum ;
}

// Time Complexity:  O(N)
// Space Complexity: O(1)
