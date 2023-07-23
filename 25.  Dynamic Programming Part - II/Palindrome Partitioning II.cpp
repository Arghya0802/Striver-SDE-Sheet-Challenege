// GFG Link:  https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
// -------------------------------------------------------------------------------------

#include <bits/stdc++.h> 

bool isPalindrome(int low , int high , string &s)
{
    while(low <= high)
    {
        if(s[low] != s[high] )  return false ;

        low++ ; high-- ;
    }

    return true ;
}

int minCuts(int start , int end , string &s , vector<int> &dp)
{
    if(isPalindrome(start , end , s) )  return 0 ;
    
    if(start >  end)  return 1e5 ;

    if(dp[start] != -1)  return dp[start] ;

    int ans = 1e5 ;

    for(int i = start ; i <= end ; i++)
    {
        if(isPalindrome(start , i , s) )
        {
            int cut = 1 + minCuts(i + 1 , end , s , dp) ;

            ans = min(ans , cut) ;
        }
    }

    return dp[start] = ans ;
}

int palindromePartitioning(string str) 
{
    int n = str.size() ;  vector<int> dp(n + 1 , -1) ;
    
    return minCuts(0 , n - 1 , str , dp) ;
}

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N) [ Both Recursive Stack Space and 1D DP is used]
