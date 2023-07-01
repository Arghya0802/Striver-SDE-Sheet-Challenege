#include <bits/stdc++.h> 

void generateAllSubsets(int ind , int n , vector<int> &subset , vector<int> &nums , vector<vector<int>> &ans)
{
    if(ind >= n)
    {
        ans.push_back(subset) ;  return ;
    }

    subset.push_back(nums[ind]) ;

    generateAllSubsets(ind + 1 , n , subset , nums , ans) ;

    subset.pop_back() ;

    generateAllSubsets(ind + 1 , n , subset , nums , ans) ;

    return ;
}

vector<vector<int>> pwset(vector<int> &v)
{
    int n = v.size() ;

    vector<int> subset ;  
    vector<vector<int>> ans ;

    generateAllSubsets(0 , n , subset , v , ans) ;

    return ans ;
}

// Time Complexity:  O(2 ^ N)
// Space Complexity: O(N) [Considering height of recursive tree only]
