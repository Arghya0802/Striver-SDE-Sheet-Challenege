// LeetCode Link: https://leetcode.com/problems/4sum/
// -----------------------------------------------------------

/* LeetCode is harder in this case because we need to find all such pairs (A, B, C, D) which are distinct and their sum equals Target.
In the case of CodeStudio, we just need to find if there exist any 4-numbers whose sum is equal to Target.

Approach:
1. Sort the given array.
2. Run two nested loops- the outer one runs from (i = 0 till n ) while the inner one runs from (j = i + 1 till n ). Our Required Sum reduces to (target - nums[i] - nums[j])
3. Inside the inner For Loop, we use the 2-pointer technique to find out if we can find any two numbers whose sum is equal to our ReqSum. If true, we return "Yes". 
4. Outside, to avoid duplicates, we can use the simple two simple while loops - while(j + 1 < n && nums[j] == nums[j + 1]) j++;  and while(i + 1 < n && nums[i] == nums[i + 1]) i++; 
5. This ensures we don't run the operation for the same elements again and again.
*/

#include <bits/stdc++.h>

string fourSum(vector<int> &arr, int target, int n) 
{
    sort(arr.begin() , arr.end() ) ;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i + 1 ; j < n ; j++)
        {
            int reqSum = target - arr[i] - arr[j] ;

            int low = j + 1 ; int high = n - 1 ;

            while(low < high)
            {
                int currSum = arr[low] + arr[high] ;

                if(currSum == reqSum)   return "Yes" ;
 
                else if(currSum < reqSum)  low++ ;

                else high-- ;  
            }

            while(j + 1 < n && arr[j] == arr[j + 1]) j++ ;
        }

        while(i + 1 < n && arr[i] == arr[i + 1]) i++ ;
    }

    return "No" ;
}

// Time Complexity:  O(N ^ 3)
// Space Complexity: O(1)
