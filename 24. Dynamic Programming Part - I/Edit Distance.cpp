// LeetCode link: https://leetcode.com/problems/edit-distance/
// -----------------------------------------------------------

#include<bits/stdc++.h>

int editDistance(int i , int j , string &s , string &t , vector<vector<int>> &dp)
{
    if(i >= s.size() )   return t.size() - j ;

    if(j >= t.size() )  return s.size() - i ;

    if(dp[i][j] != - 1)  return dp[i][j] ;
    
    int ans = INT_MAX ;

    if(s[i] == t[j] ) ans = editDistance(i + 1, j + 1 , s , t , dp) ;

    else
    {
        int erase = 1 + editDistance(i + 1, j , s , t , dp) ;

        int replace = 1 + editDistance(i + 1, j + 1 , s , t , dp) ;

        int insert = 1 + editDistance(i, j + 1 , s , t , dp) ;

        ans = min( {erase , insert , replace} ) ;
    }

    return dp[i][j] = ans ;
}

int editDistance(string str1, string str2)
{
    int m = str1.size() ; int n = str2.size() ;

    vector<vector<int>> dp(m + 1 , vector<int> (n + 1 , -1) ) ;

    return editDistance(0 , 0 , str1 , str2 , dp) ;
}

// Time Complexity:  O(M * N)
// Space Compelxity: O(M * N)
