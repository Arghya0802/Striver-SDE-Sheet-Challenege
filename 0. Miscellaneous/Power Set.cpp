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
    int n = v.size() ;  int len = 1 << n ;

    vector<vector<int>> ans ;  

    for(int num = 0 ; num < len ; num++)
    {
        vector<int> subseq ;

        for(int i = 0 ; i < n ; i++)
        {
            if(num & (1 << i) )  subseq.push_back(v[i]) ;
        }

        ans.push_back(subseq) ;
    }

    return ans ;
}

// Time Complexity for Recursion:  O(2 ^ N)
// Space Complexity for Recursion: O(N) [Recursive Stack Space]

// Time Complexity using Bit Manipulation:  O(2 ^ N * N)
// Space Complexity using Bit Manipulation: O(1) [We are not considering space required to store 2D ans[][] vector]
