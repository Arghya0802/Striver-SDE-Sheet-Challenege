// LeetCode Link:  https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// -------------------------------------------------------------------------------------------------

#include <bits/stdc++.h> 

void LPS(string &p , vector<int> &temp , int n)
{
    temp[0] = 0 ;  int i = 0 ; int j = 1 ;

    while(j < n)
    {
        if(p[i] == p[j])
        {
            i++ ; temp[j] = i ; j++ ;

        }

        else
        {
            if(i != 0)  i = temp[i-1] ;

            else
            {
                temp[j] = 0 ;  j++ ;
            }

        }

    }

    return ;
}

bool findPattern(string p, string s)
{
    int n = p.size() ; int m = s.size() ; vector <int> temp(n) ; 
    
    LPS(p , temp , n) ;

    int i = 0 ; int j = 0 ;

    while(j < m)
    {
        if(s[j]==p[i])
        {
            i++ ;  j++ ;
        }

        if(i == n)  return true ;

        else if(j < m && s[j] != p[i])
        {
            if(i != 0)  i = temp[i-1] ;
            
            else j++ ;

        }
    }

    return false;
}

// Time Complexity:  O(M + N)
// Space Complexity: O(M)
