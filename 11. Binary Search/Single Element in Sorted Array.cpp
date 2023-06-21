// LeetCode Link: https://leetcode.com/problems/single-element-in-a-sorted-array/description/
// ------------------------------------------------------------------------------------

/* Approach [Binary Search]
1. The only accurate observation is that if ( nums[mid] == nums[mid + 1] ) and we have an odd number of elements on the right half of the array, we need to update low = mid + 2 to ignore the duplicate. Otherwise, we update high = mid - 1 [because we are already standing on the right-hand side of the duplicate]
2. Similarly, if ( nums[mid] == nums[mid - 1] ) and we have an odd number of elements on the left half of the array, we update high = mid - 2. Otherwise, we update low = mid + 1 [because we are already standing on the left-hand side of the duplicate]
3. For mid == n - 1, we check with  (n - 2)th index.
4. For mid == 0, we check with 1st Index
*/

int singleNonDuplicate(vector<int>& arr)
{
	int n = arr.size() ;

	if(n == 1)  return arr[0] ;

	int low = 0 ; int high = n - 1 ;

	while(low <= high)
	{
		int mid = low + (high - low) / 2 ;

		if(mid == n - 1) // If we are the Last Index, we compare with (n - 2)th Index
		{
			if(arr[n - 1] == arr[n - 2])  high = mid - 1 ;

			else return arr[n - 1] ;
		}

		else if(mid == 0) // If we are the 0th Index, we compare with 1st Index
		{
			if(arr[0] == arr[1])  low = mid + 1 ;

			else return arr[0] ;
		}

		else if(arr[mid] == arr[mid + 1]) // If Mid and (Mid + 1) matches
		{
			int rightCnt = high - mid + 1 ; // We count how many numbers are present on the Right Side of the array

      // If the count of elements is odd, it means our answer lies on the right, so we update Low = Mid + 2
			if(rightCnt % 2 == 1)  low = mid + 2 ; 

			else high = mid - 1 ;
		}

		else if(arr[mid] == arr[mid - 1]) //If Mid and (Mid - 1) matches
		{
			int leftCnt = mid - low + 1 ; // We count how many numbers are present on the Left Side of the array

      // If the count of elements is odd, it means our answer lies on the left, so we update High = Mid - 2
			if(leftCnt % 2 == 1)  high = mid - 2 ;

			else low = mid + 1 ;
		}

		else return arr[mid] ; // Otherwise, mid is our answer so we return nums[mid] 
	}

  return -1 ;
}

// Time Complexity:  O(Log N)
// Space Complexity: O(1)
