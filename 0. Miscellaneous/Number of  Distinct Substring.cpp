#include <bits/stdc++.h> 
int distinctSubstring(string &word) 
{
    int n = word.size() ;

    unordered_set<string> hashSet ;

    for(int i = 0 ; i < n ; i++)
    {
        string s = "" ;

        for(int j = i ; j < n ; j++)
        {
            s += word[j] ;

            hashSet.insert(s) ;
        }
    }

    return (int) hashSet.size() ;
}

// Time Complexity:  O(N * 2)
// Space Complexity: O(N * 2) [At max, we would be storing all the substrings inside our set]
