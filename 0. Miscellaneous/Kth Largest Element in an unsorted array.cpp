// LeetCode Link:  https://leetcode.com/problems/kth-largest-element-in-an-array/
// -----------------------------------------------------------------------------

#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int K)
{
	priority_queue<int , vector<int> , greater<int>> minQ ;
	
	int cntQ = 0 ;

	for(int i = 0 ; i < size ; i++)
	{
		int val = arr[i] ;

		if(cntQ < K) 
		{
			minQ.push(val) ;  cntQ++ ;
		}

		else if(minQ.top() < val)
		{
			minQ.pop() ;  minQ.push(val) ;
		}
	}

	return minQ.top() ;
}

// Time Complexity:  O(N * Log K)
// Space Complexity: O(K)
