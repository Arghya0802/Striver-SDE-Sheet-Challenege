/* Approach [Greedy]
1. Pick the largest denomination possible and keep taking that denomination till you cannot take it anymore
*/

#include <bits/stdc++.h> 

int findMinimumCoins(int amount) 
{
    int coins[] = {1000 , 500 , 100 , 50 , 20 , 10 , 5 , 2 , 1} ;

    int ans = 0 ;

    for(int i = 0 ; i < 9 ; i++)
    {
        if(amount < coins[i])  continue ;

        ans += (amount / coins[i]) ;  amount %= coins[i] ;
    }    

    return ans ;
}

// Time Complexity:  O(Log Amount)
// Space Complexity: O(1)
