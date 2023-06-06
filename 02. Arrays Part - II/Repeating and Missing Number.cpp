// InterviewBit Link:  https://www.interviewbit.com/problems/repeat-and-missing-number-array/
// ---------------------------------------------------------------------------------------------------

/* Approach - 1 [Using Hash-Map or Frequency Array]
1. Simply track the frequency of all the elements present in the array.
2. Elements with frequency == 2 is the Repeating Number and frequency == 0 is the Missing Number

Approach - 2 [Solving Linear Simultaneous equations]
1. Assume X = Missing Number ; Y = Repeating Number
2. As elements are from [1, N], we can easily calculate the Sum Of the  N [totalSum] and the Sum of Square of N numbers [totalSqSum].
3. We can also calculate sum of numbers in the array and their squares and store them in currSum and currSqSum variables respectively.
4. Eqn 1: Y - X = currSum - totalSqSum 
5. Eqn 2: Y ^ 2 - X ^ 2 = currSqSum - totalSqSum 
6. Eqn 3: Y - X = (currSqSum - totalSqSum) / (currSum - totalSqSum) 
7. Solving them simultaneously gives us:
8. Y = (A + B) / 2 ; Repeating = (A + B) / 2 ;
9. X = Y - A ;  
10. A = currSum - totalSum ;     B = (currSqSum - totalSqSum) / A ;
11. Make sure we declare everything as Long Long Int, otherwise, we would suffer from Integer Overflow.
*/

#include <bits/stdc++.h>
using ll = long long int ;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	ll N = n ;

	ll totalSum = (N * (N + 1) ) / 2 ;  ll currSum = 0 ;

	ll totalSqSum = (N * (N + 1) * (2 * N + 1) ) / 6 ;  ll currSqSum = 0 ;

	for(int i = 0 ; i < n ; i++)
	{
		ll val = arr[i] ;
		currSum += val ;
		currSqSum += (val * val) ;
	}

	ll missing , repeating ;

	ll valA = currSum - totalSum ;
	ll valB = (currSqSum - totalSqSum) / valA ;

	repeating = (valA + valB) / 2 ;
	missing = repeating - valA ;

	return { missing , repeating} ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)


