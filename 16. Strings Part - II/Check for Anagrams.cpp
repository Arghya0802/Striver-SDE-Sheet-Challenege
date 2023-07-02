// LeetCode Link: https://leetcode.com/problems/valid-anagram/
// ----------------------------------------------------------

#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2)
{
    int freq[26] = {0} ;

    for(char ch : str1)  
    {
        if(ch >= 'a' && ch <= 'z')  freq[ch - 'a'] += 1 ;
    }

    for(char ch : str2)
    {
        if(ch >= 'a' && ch <= 'z')  freq[ch - 'a'] -= 1 ;
    }


    for(int i = 0 ; i < 26 ; i++)  
    {
        if(freq[i] == 0)  continue ;

        return false ;
    } 

    return true ;
}

// Time Complexity:  O(M + N)
// Space Complexity: O(1)
