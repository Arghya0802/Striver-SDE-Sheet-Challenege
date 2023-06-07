// LeetCode Link: https://leetcode.com/problems/powx-n/
// -------------------------------------------------------

/* Approach [Binary Exponentiation]: 
1. The idea is that we cannot calculate the power of X ^ N by traversing linearly if X and N are very large [X, N < 1e9]
2. To reduce our Time Complexity, we need to use the concept of Binary Exponentiation.
3. If our N is even, then we just need to call our function recur(X, N / 2) and return its square.
4. If N is odd, we need to return the square of recur(X, N / 2) * X because we would have a spare X left.
5. Lastly, if we need to take modulus by any value M, we need to do it at every step before returning so that our value stays within M,
*/

#include <bits/stdc++.h>
using ll = long long int ;

ll binaryExponentiation(ll base , ll n , ll MOD)
{
	if(n == 0)  return 1 ;

	ll ans = 0 ;

	if(n % 2 == 1) // If N is Odd
	{
		ll val = binaryExponentiation(base , n / 2 , MOD) % MOD ;
		val *= val  ;  val %= MOD ;
		val *= base ;  val %= MOD ;

		ans += val ;
	}

	else // If N is even
	{
		ll val = binaryExponentiation(base , n / 2 , MOD) ;
		val *= val ;  val %= MOD ;

		ans += val ;
	}

	return (ans % MOD) ;
}

int modularExponentiation(int x, int n, int m) 
{
	return (int) binaryExponentiation( (ll) x , (ll) n , (ll) m) ;
}

// Time Complexity:  O(Log N)
// Space Complexity: O(Log N) [Height of Recursive Tree is Log N]
