// SPOJ Link:  https://www.spoj.com/problems/AGGRCOW/
//---------------------------------------------------

/* Approach [Binary Search on Answer]
1. We need to ensure that the minDist between any two players is maximum
2. We sort the array and use binarySearch on the search space [1..... max-min]
3. This is because the minimum distance can be 1 between any 2 players can be one,  while at max it can be max-min [if we have two players]
4. Every time we calculate mid and check if such a minDist is possible or not. If true, then we need to maximize our answer thus we increment low = mid + 1. Else we update high = mid - 1
*/

#include <bits/stdc++.h> 

bool isPossible(int minDist , int k , vector<int> &nums , int n)
{
	int cnt = 1 ;  int res = 0 ;  int coordinate = nums[0] ;

	for(int i = 1 ; i < n ; i++)
	{
		if(nums[i] - coordinate >= minDist)
		{
			cnt++ ; coordinate = nums[i] ;
		}
	}

	return cnt >= k ;
}

int chessTournament(vector<int> &positions , int n ,  int c)
{
	sort(positions.begin() , positions.end() ) ;

	int low = 1 ;  int high = positions.back() - positions[0] ;

	int ans = -1 ;

	while(low <= high)
	{
		int mid = low + (high - low) / 2 ;

		if(isPossible(mid , c , positions , n) )
		{
			ans = mid ; low = mid + 1 ;
		}

		else  high = mid - 1 ;
	}

	return ans ;
}

// Time Complexity:  O(N Log Max-Element)
// Space Complexity: O(1)
