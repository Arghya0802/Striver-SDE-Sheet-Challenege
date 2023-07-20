// LeetCode Link:  https://leetcode.com/problems/longest-palindromic-substring/
// ----------------------------------------------------------------------------

#include <bits/stdc++.h>

void expandAroundCenter(int low ,  int high , string &s , pair<int , int> &ans)
{
    int n = s.size() ;

    while(low >= 0 && high < n && s[low] == s[high] )
    {
        low-- ; high++ ; 
    }

    int len = high - low - 1 ;

    if(len > ans.second)
    {
        ans.first = low + 1 ; ans.second = len ;
    }

    return ;
}

string longestPalinSubstring(string s) 
{
    pair<int,  int> ans ;  int n = s.size() ;

    for(int i = 0 ; i < n ; i++)    
    {
        expandAroundCenter(i - 1 , i + 1 , s , ans) ; // Odd Length

        expandAroundCenter(i , i + 1 , s , ans) ; // Even Length
    }

    int startIndex = ans.first ;  int maxLen = ans.second ;

    string str = s.substr(startIndex , maxLen) ;

    return str ;
}

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(1)
