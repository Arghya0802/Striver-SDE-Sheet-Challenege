// LeetCode Link:  https://leetcode.com/problems/search-in-rotated-sorted-array/
// -----------------------------------------------------------------------------

/* Approach:
1. As the array is sorted and rotated, we need to modify our binary search algorithm. We must remember we have 2 different sorted arrays inside our nums[].
2. If (nums[mid] == target) , we return mid directly.
3. Otherwise, we check which part of the array is sorted by checking nums[mid] >= nums[low]
4. If true, it means our left part is sorted- we check if our target lies in its left Part or right Part and we move our low and high accordingly.
5. Similarly, if our right part is sorted- we check if the target lies in its right Part or left Part and move our high and low accordingly.
*/

int search(int arr[] , int n, int key) 
{
    int low = 0 ; int high = n - 1 ;

    while(low <= high)
    {
        int mid = low + (high - low) / 2 ;

        if(arr[mid] == key)  return mid ;

        else if(arr[mid] >= arr[low]) // Left Part of the Array is Sorted
        {
            if(key >= arr[low] && key < arr[mid])  high = mid - 1 ;  // If Key lies on its left part, we update high = mid - 1
              
            else  low = mid + 1 ; // Else we update low = mid + 1 and move to its right part
        }

        else // Right Part of the Array is sorted
        {
            if(key > arr[mid] && key <= arr[high])  low = mid + 1 ; // If Key lies on its right part, we update low = mid + 1
                
            else high = mid - 1 ; // Else we update high = mid - 1 and move to its left part
        }
    }

    return -1 ;
}

// Time Complexity:  O(Log N)
// Space Complexity: O(1)
