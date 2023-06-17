// GFG Link:  https://practice.geeksforgeeks.org/problems/subset-sums2234/1
// ------------------------------------------------------------------------

/* Approach [Recursion]
1. Use pick and skip concepts to generate all the subsets- but we don't need the sum actually, we only need their sum.
2. We can easily get their sum using a sum variable and push it into our ans[] vector whenever we have reached our base case.
*/

#include <bits/stdc++.h> 

void allSubsetsSum(int ind , int sum , int n , vector<int> &nums , vector<int> &ans)
{
    if(ind >= n)
    {
        ans.push_back(sum) ;  return ;
    }

    // Pick i-th element
    sum += nums[ind] ;
    allSubsetsSum(ind + 1 , sum , n , nums , ans) ;

    // Backtrack and undo the change
    sum -= nums[ind] ;

    // Skip i-th Element
    allSubsetsSum(ind + 1 , sum , n , nums , ans) ;

    return ;
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans ;

    allSubsetsSum(0 , 0 , num.size() , num , ans) ;
    
    sort(ans.begin() , ans.end() ) ; // To store all the subset sums in sorted order
    
    return ans ;
}

// Time Complexity:  O(2 ^ N + O(2 ^ N + Log(2 ^ N)) [For generating subsets and sorting them to get the required order]
// Space Complexity: O(N) [Ignoring Space used for 2D ans[][] vector ]
