// LeetCode Link:  https://leetcode.com/problems/maximum-product-subarray/
// ---------------------------------------------------------------------

#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	int leftProd = arr[0] ;  int rightProd = arr[0] ;
	int prod = 1 ;

	for(int i = n - 1 ; i >= 0 ; i--) 
	{
		prod *= arr[i] ;  rightProd = max(rightProd , prod) ;
	
		if(prod == 0)  prod = 1 ;
	}

	prod = 1 ;

	for(int i = 0 ; i < n ; i++)
	{
		prod *= arr[i] ;  leftProd = max(leftProd , prod) ;
	
		if(prod == 0)  prod = 1 ;
	}

	
	return max(leftProd , rightProd) ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
