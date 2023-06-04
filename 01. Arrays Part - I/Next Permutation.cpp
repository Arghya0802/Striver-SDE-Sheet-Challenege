// LeetCode Link:  https://leetcode.com/problems/next-permutation/
//------------------------------------------------------------------

// Approach -- A very important question which can't be solved without knowing the algorithm
// 1.  Find the BreakPoint where nums[i] < nums[i + 1]  --> Store the Index if BreakPoint is found
// 2. If no breakPoint is found, just reverse the array and return 
// 3. If we have received a breakPoint, we need to find the first number from the back which is just greater than our breakPoint val { nums[ind] } 
// 4. Swap the values - swap(nums[ind]  , nums[i]) where nums[i] is just greater than nums[ind]
// 5. Now to get the just next Permutation, reverse the rest part of the array from [ind + 1 , n - 1]

// ------------------------------------------------------------------------

#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    // 1. Find the BreakPoint
    
    int ind = -1 ;

    for(int i = n - 2 ; i >= 0 ; i--)
    {
        if(permutation[i] < permutation[i + 1])
        {
            ind = i ; break ;
        }
    }

    // 2. If we didn't find any BreakPoint, it means we are at the Lexicographically Largest Permutation
    // We should just reverse the given vector and return ;

    if(ind == -1) 
    {
        reverse(permutation.begin() , permutation.end() ) ;  
        
        return permutation ;
    }

    // 3. We need to swap the first largest element greater than BreakPoint Element and swap their places

    for(int i = n - 1 ; i > ind ; i--)
    {
        if(permutation[i] > permutation[ind])
        {
            swap(permutation[i] , permutation[ind] ) ;  break ;
        }
    }

    // 4. Lastly, we need to reverse the remaining part of the array so that it becomes smallest from (ind + 1 , n]

    reverse(permutation.begin() + ind + 1 , permutation.end() ) ;

    return permutation ;

}

// Time Complexity:  O(N)
// Space Complexity: O(1) [In-Place Next Permutation is calculated]
