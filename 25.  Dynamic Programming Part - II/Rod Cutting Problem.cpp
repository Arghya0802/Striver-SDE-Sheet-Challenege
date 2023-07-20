
#include<bits/stdc++.h>

int maxProfit(int ind , int len , vector<int> &price , vector<vector<int>> &dp)
{
	if(len == 0 || ind >= price.size() )  return 0 ;
	
	if(dp[ind][len] != -1)  return dp[ind][len] ;
	
	int skip = maxProfit(ind + 1 , len, price , dp) ;  int pick = 0 ;

	if(ind + 1 <= len) 
		pick = price[ind] + maxProfit(ind , len - (ind + 1) , price , dp) ;

	return dp[ind][len] = max(pick , skip) ;
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n + 1 , vector<int> (n + 1 , -1) ) ;

	return maxProfit(0 , n , price , dp) ;
}

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N ^ 2)
