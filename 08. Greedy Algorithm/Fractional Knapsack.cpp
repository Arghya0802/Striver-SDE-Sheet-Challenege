// GFG Link: https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
// ---------------------------------------------------------------------------------------

/* Approach [Greedy]
1. We use the Greedy approach because we can choose an item only once and we are allowed to leave maxCapacity or Weight of the bag != 0 if we don't have sufficient weight.
2. Also, we allowed breaking items to fit accordingly. This indicates that a Greedy approach is applicable.
3. Now, which items should be picked first and which at the end? We pick only those items whose (price/weight) ratio is higher. This helps us to gain more profit by using lesser weights. 
4. Thus we sort the array item[] accordingly and pick elements till our maxCapacity > 0.
5. For breaking any item, we follow the unitary method - W * (value/weight)
*/

#include <bits/stdc++.h> 
using pp = pair<int , int> ;

static bool cmp(pp &A , pp &B)
{
    double v1 = (double) A.second / (double) A.first ;
    double v2 = (double) B.second / (double) B.first ;

    return v1 > v2 ;
}

double maximumValue (vector<pair<int, int>>& items, int n, int W)
{
    // ITEMS contains {weight, value} pairs.

    sort(items.begin() , items.end() , cmp) ;

    double maxProfit = 0 ;

    for(int i = 0 ; i < n ; i++)
    {
        if(W >= items[i].first)
        {
            maxProfit += items[i].second ; W -= items[i].first ;
        }

        else // Our item's weight > W, so we need to break the item and break out as W becomes 0
        {
            maxProfit += W * ( (double) items[i].second / (double) items[i].first) ; 
            break ;
        }
    }

    return maxProfit ;
}

// Time Complexity:  O(N * Log N)
// Space Complexity: O(1)
