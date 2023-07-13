// LeetCode link:  https://leetcode.com/problems/longest-common-subsequence/
// -------------------------------------------------------------------------

#include <bits/stdc++.h>

int lcs(int i , int j , int m , int n , string &s , string &t , vector<vector<int>> &dp)
{
	if(i == m || j == n)  return 0 ;

	if(dp[i][j] != -1)  return dp[i][j] ;
	
	int ans = 0 ;

	if(s[i] == t[j])  ans = 1 + lcs(i + 1 , j + 1 , m , n , s , t , dp) ;

	else
	{
		int opS = lcs(i + 1 , j , m , n , s , t , dp) ;
		int opT = lcs(i , j + 1 , m , n , s , t , dp) ;

		ans = max(opS , opT) ;
	}

	return dp[i][j] = ans ;
}

int lcs(string s, string t)
{
	int m = s.size() ;  int n = t.size() ;

	vector<vector<int>> dp(m + 1 , vector<int> (n + 1 , -1) ) ;

	return lcs(0 , 0 , m , n , s , t , dp) ;
}

// Time Complexity:  O(M * N)
// Space Complexity: O(M * N)
