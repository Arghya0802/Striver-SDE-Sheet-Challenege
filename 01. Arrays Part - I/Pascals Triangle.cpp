// LeetCode Link: https://leetcode.com/problems/pascals-triangle/
//-----------------------------------------------------------

// Appraoch
// 1. Declare a 2D vector and push {1} for N = 1 and {1 , 1} for N = 2
// 2. For N > 2, use the formula to calculate Pascal's Coefficients: currRow[i] = ans[ind - 1][i] + ans[ind - 1][i + 1]
// 3. Make sure we traverse to Len - 1 otherwise we would get array out of bound array
// 4. Return the vector
// ---------------------------------------------------------------------

#include <bits/stdc++.h>
using ll = long long int ;

vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<ll>> ans ;
    ans.push_back({1}) ; // We make our First Row ready

    if(n == 1)  return ans ; // If N = 1, we directly return our ans ;

    ans.push_back({1 , 1}) ; // We make our Second Row ready

    if(n == 2)  return ans ;

    for(int ind = 2 ; ind < n ; ind++)
    {
        vector<ll> currRow ; currRow.push_back(1) ; // Starting and ending  of all the Pascal Rows contains the value 1
        int len = ans[ind - 1].size() ;

        for(int i = 0 ; i < len - 1 ; i++)
        {
            ll a = ans[ind - 1][i] ; ll b = ans[ind - 1][i + 1] ;
            ll val = a + b ;
            currRow.push_back(val) ;
        }
        
        currRow.push_back(1) ;  ans.push_back(currRow) ; // At the end of each iteration, we push our currRow into our ans[][] vector
    }

    return ans ;
}
// --------------------------------------------------------------------------------
// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N ^ 2) [If we consider the space taken by the 2D vector]

