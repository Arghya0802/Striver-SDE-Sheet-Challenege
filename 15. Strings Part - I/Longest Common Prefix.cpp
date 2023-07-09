// LeetCode Link:  https://leetcode.com/problems/longest-common-prefix/
// --------------------------------------------------------------------

#include <bits/stdc++.h>

string longestCommonPrefix(vector<string> &arr, int n)
{
    sort(arr.begin() , arr.end() ) ;

    string ans = "" ;  
    
    string A = arr[0] ;  string B = arr.back() ;

    int lenA = arr[0].size() ;  int lenB = arr.back().size() ;

    for(int i = 0 ; i < lenB ; i++)
    {
        if(i == lenA || A[i] != B[i])  break ;

        ans += B[i] ;
    }

    return ans ;
}

// Time Complexity:  O(N * Log N)
// Space Complexity: O(N) [For storing the Answer String]
