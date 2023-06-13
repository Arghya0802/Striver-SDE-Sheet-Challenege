// LeetCode Link:  https://leetcode.com/problems/trapping-rain-water/description/
// ------------------------------------------------------------------------------

/* Approach 1 [Use prefix and Suffix arrays]:
1. We can easily check the amount of storage of water that can be stored at a particular height as 
                               res += min(leftMax[i], rightMax[i]) - height[i]
2. Thus, we can use 2 arrays- leftMax[] and rightMax[] to help us calculate our answer. leftMax[] stores the maximum from (i = 0 till N) while rightMax stores the maximum from (n - 1 till 0). They work as prefix and suffix arrays respectively.


Approach 2 [Two-Pointers technique ]
1. Instead of using the extra space, we can calculate the total water stored using two pointers and storing the maximum heights from left and right we have encountered till now- left = 0, right = n - 1, and maxLeft = height[0] and maxRight = height[n - 1] initially.
2. Before calculating, we need to check if our maxLeft <= maxRight or not. If true, it means we have a building on the right of the i-th index with a height at least >= maxLeft, thus we can store water.
3. Water stored can be calculated as maxLeft - height[i]. If water stored becomes negative, we don't add it to our resultant answer res, because that's not practically possible.  We also update our maxLeft if heights[i] >= maxLeft and make our left pointer increment by 1.
4. Else if our maxRight < maxLeft, we again calculate the water stored in the i-th index as maxRight - height[i] and it to our res if and only if its value >= 0. Also, we update our maxRight if height[i] >= maxRight and make our right pointer decrement by 1. 
5. At the end, we return our res variable.
*/

#include <bits/stdc++.h> 
using ll = long long int ;

long getTrappedWater(long arr[] , int n)
{
    ll res = 0 ;

    int left = 0 ; int right = n - 1 ;

    ll maxLeft = arr[0] ;  ll maxRight = arr[n - 1] ;

    while(left <= right)
    {
        if(maxLeft <= maxRight)
        {
            ll water = maxLeft - arr[left] >= 0 ? maxLeft - arr[left] : 0 ;

            res += water ;

            if(maxLeft <= arr[left])  maxLeft = arr[left] ;

            left++ ;
        }

        else
        {
            ll water = maxRight - arr[right] >= 0 ? maxRight - arr[right] : 0 ;

            res += water ;

            if(maxRight <= arr[right])  maxRight = arr[right] ;

            right-- ;
        }
    }

    return res ;
}

// Time Complexity:  O(N)
// Space Complexity: O(1)
