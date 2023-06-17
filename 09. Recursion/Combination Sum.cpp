// LeetCode Link: https://leetcode.com/problems/combination-sum/description/
// -------------------------------------------------------------------------

/* Approach [Similar to Subsets - I]
1. Simple Pick & Skip logic.
2. We can pick an element as many times as we want.
3. We only pick those subsets whose sum is equal to Target or K.
*/

#include <bits/stdc++.h>

void subsetSumEqualK(int ind , int n , int target , vector<int> &subset , vector<int> &nums , vector<vector<int>> &ans)
{
    if(ind >= n)
    {
        if(target == 0 && !subset.empty() )  ans.push_back(subset) ;
        
        return ;
    }

    target -= nums[ind] ;  subset.push_back(nums[ind]) ;

    subsetSumEqualK(ind + 1 ,  n,  target, subset, nums, ans) ; // Ask recursion to do rest of the task

    target += nums[ind] ;  subset.pop_back() ;  // Backtrack and undo the change 
    

    subsetSumEqualK(ind + 1 , n , target , subset , nums , ans) ;  // Don't Pick the i-th Element

    return ;
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> &arr, int n, int k)
{

    vector<vector<int>> ans ;
    vector<int> subset ;

    subsetSumEqualK(0 , n , k , subset , arr , ans) ;

    return ans ;
}

// Time Complexity:  O(2 ^ N)
// Space Complexity: O(N) [Ignoring Space taken by 2D ans[][] vector]
