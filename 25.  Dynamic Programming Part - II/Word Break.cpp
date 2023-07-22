// LeetCode link:  https://leetcode.com/problems/word-break/
// ----------------------------------------------------------

#include <bits/stdc++.h>

int wordBreak(int ind , string &target , unordered_set<string> &set , vector<int> &dp)
{
    if(ind >= target.size() )  return 1 ;

    if(dp[ind] != -1)  return dp[ind] ;
    
    string prefix = "" ;

    for(int i = ind ; i < target.size() ; i++)
    {
        prefix += target[i] ;

        if(set.find(prefix) != set.end() ) 
        {
            if(wordBreak(i + 1 , target , set , dp) )  return 1 ;
        }
    }

    return dp[ind] = 0 ;
}

bool wordBreak(vector <string> &arr, int n, string &target) 
{
    unordered_set<string> set ;

    for(auto it : arr)  set.insert(it) ;

    int len = target.size() ; vector<int> dp(len + 1 , -1) ;
    
    return wordBreak(0 , target , set , dp) ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N) [Dp array + Unordered_Set to store all the strings ]
