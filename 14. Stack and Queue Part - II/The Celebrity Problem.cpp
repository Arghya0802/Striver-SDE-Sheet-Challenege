#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) 
{
 	int i = 0 ; int j = n - 1 ;

	while(i < j)
	{
		if(knows(i , j) ) i++ ;

		else j-- ;
	}
	
	for(int node = 0 ; node < n ; node++)
	{
		if(node == i)  continue ;

		if(knows(node , i) == false || knows(i , node) == true)  return -1 ;
	}

	return i ;
}

// Time Complexity:  O(N)
// Space Complexity: O(1)
