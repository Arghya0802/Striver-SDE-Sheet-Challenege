// LeetCode Link:  https://leetcode.com/problems/roman-to-integer/
// ---------------------------------------------------------------

#include <bits/stdc++.h>

int romanToInt(string &s) 
{
    int n = s.size() ;    

    int ans = 0 ;  unordered_map<char , int> map ;

    map['I'] = 1 ;    map['V'] = 5 ;
    map['X'] = 10 ;   map['L'] = 50 ;
    map['C'] = 100 ;  map['D'] = 500 ;  
    map['M'] = 1000 ;

    for(int i = 0 ; i < n ; i++)
    {
        char ch = s[i] ;

        if(i == n - 1) 
        {
            ans += map[ch] ;  continue ;
        }

        if(ch == 'I' && s[i + 1] == 'V')  ans -= map[ch] ;
        else if(ch == 'I' && s[i + 1] == 'X')  ans -= map[ch] ;

        else if(ch == 'X' && s[i + 1] == 'L')  ans -= map[ch] ;
        else if(ch == 'X' && s[i + 1] == 'C')  ans -= map[ch] ;

        else if(ch == 'C' && s[i + 1] == 'D')  ans -= map[ch] ;
        else if(ch == 'C' && s[i + 1] == 'M')  ans -= map[ch] ;

        else ans += map[ch] ;
    }

    return ans ;
}

// Time Complexity:  O(N)
// Space Complexity: O(1)
