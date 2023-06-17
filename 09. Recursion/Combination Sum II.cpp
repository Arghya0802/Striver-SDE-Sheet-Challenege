// LeetCode Link:  https://leetcode.com/problems/combination-sum-ii/
// -----------------------------------------------------------------

/* Approach [ Similar to Subset Sum - II ]
1. Similar to Combination Sum - I
2. We pick and skip to generate all the subsets.
3. While skipping, we skip all the occurrences of the current element.
4. We only pick those subsets whose sum is equal to Target or K
*/

#include <bits/stdc++.h>

void subsetSumEqualsK(int ind , int n , int target , vector<int> &subset , vector<int> &nums , vector<vector<int>> &ans)
{
	if(ind == n) // Base Case
    {
		// Include only those subsets whose sum is equal to Target
        if(target == 0)  ans.push_back(subset) ; 

        return ;
    }    

	// Pick i-th Element
    target -= nums[ind] ;  subset.push_back(nums[ind]) ;
    
    subsetSumEqualsK(ind + 1 , n , target , subset , nums , ans) ; // Ask Recursion to do rest of the task

    target += nums[ind] ;  subset.pop_back() ; // Backtrack and undo the change
    
	// Skip all the Duplicate occurrences of the Current Element
    while(ind + 1 < n && nums[ind] == nums[ind + 1])  ind++ ; 
    
    subsetSumEqualsK(ind + 1 , n , target , subset , nums , ans) ; // Skip the i-th Element and ask Recursion to do rest of the task
    
    return ;
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	sort(arr.begin() , arr.end() ) ; // Sort the arr[] vector so that we can ski duplcate elements

	vector<vector<int>> ans ;

	vector<int> subset ;

	subsetSumEqualsK(0 , n , target , subset , arr , ans) ;

	sort(ans.begin() , ans.end() ) ; // Final ans[][] vecor is sorted as per the problem statement

	return ans ;
}

// Time Complexity:  O(2 ^ N)
// Space Complexity: O(N) [Ignoring 2D ans[][] vector]
