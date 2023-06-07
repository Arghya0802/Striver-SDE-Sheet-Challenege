// LeetCode Link: https://leetcode.com/problems/majority-element/
// ----------------------------------------------------------

/* Approach [ Bayer Moore's Majority Voting Algo ]:
1. If we need to find the element occurring > N / 2 times in O(N) Time and O(1) Space Complexity respectively, we need to follow this algorithm.
2. Bayer Moore's Majority Voting Algo is based on the Cancellation technique.
3. The idea is if we have an element occurring > N / 2 times, it won't be ever canceled by the rest of the elements combining together.
4. We need to do a manual check confirming that our majority element is right or not before returning it's value.
*/

#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) 
{
	int majorEle = 0 ; int cnt = 0 ;

	for(int i = 0 ; i < n ; i++)
	{
		if(cnt == 0)  majorEle = arr[i] ;

		if(majorEle == arr[i])  cnt++ ;

		else  cnt-- ;
	}

	int freq = 0 ;

	for(int i = 0 ; i < n ; i++)
	{
		if(majorEle == arr[i])  freq += 1 ;
	}

	return freq * 2 > n  ? majorEle : -1 ;
}

// Time Complexity:  O(N)
// Space Complexity: O(1)
