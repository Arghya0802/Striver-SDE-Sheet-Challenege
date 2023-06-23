// LeetCode Link: https://leetcode.com/problems/kth-largest-element-in-an-array/description/
//------------------------------------------------------------------------------------------

// Approach: Use Max-Heap to reduce the Time Complexity to O(N * Log K)

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
  priority_queue<int> maxHeap ;  int cntMax = 0 ; // For Calculating K-th Smallest Element
	priority_queue<int , vector<int> , greater<int>> minHeap ;  int cntMin = 0 ; // For calculating K-th Largest Element

	for(auto val : arr)
	{
		if(cntMax < k)  
		{
			maxHeap.push(val) ;  cntMax++ ;
		}

		else if(maxHeap.top() > val)  
		{
			maxHeap.pop() ;  maxHeap.push(val) ;
		}

		if(cntMin < k) 
		{
			minHeap.push(val) ;  cntMin++ ;
		}

		else if(minHeap.top() < val)
		{
			minHeap.pop() ; minHeap.push(val) ;
		}
		
	}

	return {maxHeap.top() , minHeap.top() } ;
}

// Time Complexity:  O(N * Log K)
// Space Complexity: O(2 * K)
