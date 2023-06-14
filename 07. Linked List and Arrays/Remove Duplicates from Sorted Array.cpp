// LeetCode Link:  https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// ----------------------------------------------------------------------------------

/* Approach:
1. As the array is sorted, duplicates must occur consecutively.
2. Thus, we can keep track of the previous element using prev, initialized to nums[0]. And K = 1 to return the length of the modified nums[] without having duplicates.
3. We check whether our prev != nums[i]. If true, we update nums[k++] = nums[i] and also update our prev as nums[i] and increment k by 1.
4. At the end, we return K.
*/

int removeDuplicates(vector<int> &arr, int n) 
{
	int k = 1 ;  int prev = arr[0] ;

	for(int i = 1 ; i < n ; i++)
	{
		if(prev != arr[i])
		{
			arr[k] = arr[i] ;  k++ ;

			prev = arr[i] ;
		}
	}

	return k ;
}

// Time Complexity:  O(N)
// Space Complexity: O(1)
