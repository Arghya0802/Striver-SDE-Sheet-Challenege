// LeetCode link:  https://leetcode.com/problems/string-to-integer-atoi/
// --------------------------------------------------------------------

#include <bits/stdc++.h> 

int atoi(string &str) 
{
    int n = str.size() ;

    int sign = 1 ;

    if(str[0] == '-')  sign = -1 ;

    int ans = 0 ;

    for(int i = 0 ; i < n ; i++)
    {
        char ch = str[i] ;

        if(ch >= '0' && ch <= '9')  
        {
            ans *= 10 ;  ans += (ch - '0') ;
        }
    }

    return (ans * sign) ;
}

// Time Complexity:  O(N)
// Space Complexity: O(1)
