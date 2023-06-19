// Link:  https://leetcode.com/problems/permutations/
// --------------------------------------------------

/* Approach [ Generate all Permutations by swapping Indices ]
1. As we are asked to generate all permutations, we can do so by swapping indices - s[i] and s[ind]
2. ind is the parameter that we will pass to our recursive function
3. We run a for loop from i = ind till i < n and for every index s[i], we swap it with s[ind] and call recur(ind + 1, s) and ask it to generate rest of the permutations
4. Whenever our ind becomes equal to s.size(), we put it inside our ans[] vector
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
// Space Complexity: O(N) [Recursive Stack Space] + O(N!) [For Storing all the Permutations inside ans[] vector]
