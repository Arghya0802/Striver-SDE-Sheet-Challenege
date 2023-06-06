// LeetCode Link: https://leetcode.com/problems/merge-sorted-array/
// -------------------------------------------------------------------------------------

/* Approach:
1. We will traverse from the back using 3 pointers - i, j and k 
2. (i,j) iterates over arr1[] and arr2[] respectively while k is used to fill the array arr1[] Completely
3. Before returning, we must ensure all the elements of arr1[] and arr2[] are traversed or not.
4. Merging is done in-place without the use of any extra space or sort() function.
*/

#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) 
{
	int i = m - 1 ,  j = n - 1 , k = (m + n - 1) ;

	while(i >= 0 && j >= 0)
	{
		if(arr1[i] < arr2[j])
		{
			arr1[k] = arr2[j] ; k-- ; j-- ;
		}

		else  
		{
			arr1[k] = arr1[i] ; k-- ; i-- ;
		}
	}

	for(; i >= 0 ; i--)  arr1[k--] = arr1[i] ;
	
	for(; j >= 0 ; j--)  arr1[k--] = arr2[j] ;

	return arr1 ;  
}

// Time Complexity:  O(M + N)
// Space Complexity: O(1)
