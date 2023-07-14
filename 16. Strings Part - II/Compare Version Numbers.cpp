// LeetCode Link:  https://leetcode.com/problems/compare-version-numbers/
// -----------------------------------------------------------------------

#include <bits/stdc++.h> 

int compareVersions(string a, string b) 
{
    int m = a.size() ; int n = b.size() ;
    int i = 0 ; int j = 0 ;

    while(i < m || j < n)
    {
        long long valA = 0 ;  long long valB = 0 ;

        while(i < m && a[i] != '.')
        {
            valA *= 10 ;  valA += a[i++] - '0' ;
        }

        while(j < n && b[j] != '.')
        {
            valB *= 10 ; valB += b[j++] - '0' ;
        }

        if(valA > valB)  return 1 ;

        if(valB > valA)  return -1 ;

        i++ ; j++ ;
    }

    return 0 ;
}

// Time Complexity:  O(N)
// Space Complexity: O(1)
