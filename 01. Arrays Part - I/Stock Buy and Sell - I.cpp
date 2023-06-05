// Link:  https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// ----------------------------------------------------------------------------------

/* Approach: [2D DP solution will not work] 
1. Initially our costPrice = nums[0] and check if our prices[i]  >= costPrice.
2. If true, update our maxProfit = max(maxProfit , prices[i] - costPrice) 
3. Otherwise, our costPrice is less, so we need to update our costPrice = prices[i].
4. Return maxProfit at the end.
*/

#include <bits/stdc++.h> 

int maximumProfit(vector<int> &prices)
{
    int n = prices.size() ;
    
    int costPrice = prices[0] ;
    
    int maxProfit = 0 ;

    for(int i = 1 ; i < n ; i++)
    {
        if(costPrice <= prices[i] )  maxProfit = max(maxProfit , prices[i] - costPrice) ;

        else  costPrice = prices[i] ;
    }

    return maxProfit ;
}

// Time Complexity:  O(N)
// Space Complexity: O(1)
