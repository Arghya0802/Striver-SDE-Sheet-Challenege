// LeetCode Link: 
// -----------------------------------------------------------

/* Approach:
1. Sort the array or vector nums[] and declare a 2D ans[][] vector.
2. Start a for loop from i = 0 till N
3. Use 2-pointers to get our target which is K - nums[i]
4. Low = i + 1 and High = n - 1 ;
5. If at any moment, our sum becomes equal to our target, we push the 3-numbers inside our ans [][] vector.
6. To skip duplicates we use, while(i + 1 < n && nums[i] == nums[i + 1) i++; 
*/

#include <bits/stdc++.h> 

vector<vector<int>> findTriplets(vector<int> &arr, int n, int K) 
{
	sort(arr.begin() , arr.end() ) ;

	vector<vector<int>> ans ;

	for(int i = 0 ; i < n ; i++)
	{
		int target = K - arr[i] ;

		int low = i + 1 ; int high = n - 1 ;

		while(low < high)
		{
			int sum = arr[low] + arr[high] ;

			if(sum == target)
			{
				int a = arr[i] , b = arr[low] , c = arr[high] ;

				ans.push_back( {a , b , c} ) ;

				while(low < high && b == arr[low] ) low++ ;

				while(low < high && c == arr[high] ) high-- ;
			}

			else if(sum < target)  low++ ;

			else high-- ;
		}

		while(i + 1 < n && arr[i] == arr[i + 1] ) i++ ;
	}

	return ans ;
}

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(1)
