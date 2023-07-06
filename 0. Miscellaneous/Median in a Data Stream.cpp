// LeetCode Link:  https://leetcode.com/problems/find-median-from-data-stream/
// --------------------------------------------------------------------------

#include <bits/stdc++.h>

int findMedian(priority_queue<int> &smallQ , priority_queue<int , vector<int> , greater<int>> &largeQ)
{
	if(smallQ.size() == largeQ.size() ) return (smallQ.top() + largeQ.top() ) / 2 ;

	else if(smallQ.size() > largeQ.size() )  return smallQ.top() ;

	else return largeQ.top() ;
}

vector<int> findMedian(vector<int> &arr, int n)
{
	priority_queue<int> smallQ ; // Max-Heap
	priority_queue<int , vector<int> , greater<int>> largeQ ; // Min-Heap

	vector<int> ans ;

	for(int i = 0 ; i < n ; i++)
	{
		int val = arr[i] ;
		
		smallQ.push(val) ;

		if(!smallQ.empty() && !largeQ.empty() && smallQ.top() > largeQ.top() )
		{
			int top = smallQ.top() ;  smallQ.pop() ;
			
			largeQ.push(top) ;
		}

		int s1 = smallQ.size() ; int s2 = largeQ.size() ;

		if(s1 - s2 > 1)
		{
			int top = smallQ.top() ; smallQ.pop() ;
			
			largeQ.push(top) ;
		}

		if(s2 - s1 > 1)
		{
			int top = largeQ.top() ; largeQ.pop() ;
			
			smallQ.push(top) ;
		}


		int median = findMedian(smallQ , largeQ) ;

		ans.push_back(median) ;
	}

	return ans ;
}

// Time Complexity:  O(N * Log N)
// Space Complexity: O(N)
