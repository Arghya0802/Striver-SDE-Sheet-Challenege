// LeetCode link:  https://leetcode.com/problems/subsets-ii/
// ----------------------------------------------------------

/* Approach [Recursion]
1. Sort the given nums[] 
2. Use Pick and Skip logic.
3. While skipping, skip all the occurrences of the current element.
*/

#include <bits/stdc++.h> 

void uniqueSubsets(int ind , int n , vector<int> &subset , vector<int> &nums , vector<vector<int>> &ans)
{
    if(ind >= n) // Base Case
    {
        ans.push_back(subset) ; // Include the Subset into our ans[][]
        return ;
    }

    subset.push_back(nums[ind]) ; // Pick i-th Element

    uniqueSubsets(ind + 1 , n , subset , nums , ans) ;  // Ask Recursion to do rest of the task

    subset.pop_back() ; // Backtrack and undo the change

    // Skip all the occurrences of the Current Element so that we don't egt duplicate subsets
    while(ind + 1 < n && nums[ind] == nums[ind + 1])  ind++ ;

    uniqueSubsets(ind + 1 , n , subset , nums , ans) ; // Don't Pick i-th Element

    return ;
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    sort(arr.begin() , arr.end() ) ;

    vector<vector<int>> ans ;  

    vector<int> subset ;

    uniqueSubsets(0 , n , subset , arr , ans) ;

    sort(ans.begin() , ans.end() ) ;
    
    return ans ;
}

// Time Complexity:  O(2 ^ N + 2 ^ N + Log(2 ^ N)) [For sorting the ans[][] vector]
// Space Complexity: O(N) [Ignoring space used by 2D ans[][] vector]
