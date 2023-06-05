// LeetCode Link:  https://leetcode.com/problems/sort-colors/
//----------------------------------------------------------------

// Approach: The Dutch National Flag Algorithm
// 1. Initialise low = 0 , mid = 0 , high = n - 1.
// 2. Run a while loop for mid <= high.
// 3. Now, we always check what value we are getting at nums[mid] always.
// 4. If nums[mid] == 0, we need to push it at the beginning, so we swap(nums[low], nums[mid]) and increment both low and mid by 1.
// 5. Else If nums[mid] == 2, we need to push it at the end, so we swap(nums[mid], nums[high]) and decrement only high by 1. This is to handle the case when nums[high] == 0, we need to push that 0 at the beginning of the array in the next iteration.
// 6. Lastly, If nums[mid] == 1, we are okay with it because 1 should be coming in the middle. So we increment mid by 1.

//---------------------------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h> 

void sort012(int arr[] , int n)
{
   int low  = 0 ;
   int mid  = 0 ;
   int high = n - 1 ;

   while(mid <= high)
   {
      if(arr[mid] == 0)
      {
         swap(arr[mid] , arr[low]) ;
         low++ ; mid++ ;
      }

      else if(arr[mid] == 2)
      {
         swap(arr[mid] , arr[high]) ;
         high-- ;
      }

      else  mid++ ;
   }

   return ;
}

// Time Complexity:  O(N) [Single Traversal only]
// Space Complexity: O(1)
