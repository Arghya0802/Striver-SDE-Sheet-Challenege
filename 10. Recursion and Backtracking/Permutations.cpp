// Link:  https://leetcode.com/problems/permutations/
// --------------------------------------------------

/* Approach  
*/

#include <bits/stdc++.h> 

void generatePemutations(int ind , int n , string &s , vector<string> &ans)
{
    if(ind == n)
    {
        ans.push_back(s) ;  return ;
    }

    for(int i = ind ; i < n ; i++)
    {
        swap(s[ind] , s[i]) ;

        generatePemutations(ind + 1 , n , s , ans) ;

        swap(s[ind] , s[i]) ;
    }

    return ;
}

vector<string> findPermutations(string &s) 
{
    vector<string> ans ;

    generatePemutations(0 , s.size() , s , ans) ;

    return ans ;
}

// Time Complexity:  O(N!)
// Space Complexity: O(N!)
