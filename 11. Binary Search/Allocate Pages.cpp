// InterviewBit Link:  https://www.interviewbit.com/problems/allocate-books/
// --------------------------------------------------------------------------

/* Approach [Binary Search on Answer]
1. We can see that our answer will always lie between [ Max element ...... sum of all array elements]. Thus we can apply Binary search on Answer. 
2. We figure out the range by applying the simple logic - if N = 1, he needs to finish all the chapters in a single day, so our High = Sum of Array Elements. Similarly, if M >= N, he can finish one book every day- so Low = Max-Element of Array [because we need to return the Maximum Time he spends on a single day]
3. We calculate a mid and check if its possible for the student to finish all M chapters- if so, we update our ans variable as mid, and as we are looking to minimize our answer, we move to the left by adding high = mid - 1
4. Else, it is not a valid answer so we update low = mid + 1 and try for a bigger value.
5. At the end, we return our answer.
*/

#include <bits/stdc++.h> 
using ll = long long int ;

bool isPossible(ll maxTime , int n , vector<int> &nums)
{
	int cnt = 0 ; ll chapsRead = 0 ;

	for(auto book : nums)
	{
		// if(book > maxTime)  return false ;

		if(chapsRead + book <= maxTime)  chapsRead += book ;

		else
		{
			cnt++ ;  chapsRead = book ;
		}
	}

	cnt++ ;

	return cnt <= n ;
}

long long ayushGivesNinjatest(int n, int m, vector<int> &time) 
{	
	ll sum = 0 ;

	for(auto it : time)  sum += it ;

	ll low = *max_element(time.begin() , time.end() ) ;
	ll high = sum ;
	ll ans = -1 ;

	while(low <= high)
	{
		ll mid = low + (high - low) / 2 ;

		if(isPossible(mid , n , time) )
		{
			ans = mid ; 
			high = mid - 1 ;
		}

		else  low = mid + 1 ;
	}

	return ans ;
}

// Time Complexity:  O(N * Log N)
// Space Complexity: O(1)
