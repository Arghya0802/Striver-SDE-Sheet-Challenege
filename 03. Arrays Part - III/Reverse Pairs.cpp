// LeetCode Link:  https://leetcode.com/problems/reverse-pairs/description/
// ------------------------------------------------------------------------------------

/* Approach [Slight Variation of Count Inversion]
1. The question is similar to count inversion with a slight tweak. Instead of counting all the pairs which satisfy the condition nums[i] > nums[j] when (i < j), we need to check for all such pairs which satisfy the condition nums[i] > 2 * nums[j] when (i < j).
2. The optimal solution to the problem will be using Merge-Sort only. However, our countInversions() function needs to be revamped to countReversePairs() and slight modification is required inside it.
3. We need to iterate for all the elements in the left half of the array, from i = low till i <= mid; But we can keep a check which can help us to give the count of all valid pairs in less than O(N ^ 2) Time Complexity. We initialize our right pointer as mid + 1.
4. Inside our for loop we would run a while loop which runs till (right <= high && nums[left] > 2 * nums[right]) right++;  This would help us to get the count of all the valid pairs without checking or all the elements and consuming O(N) Time for every iteration.
5. This approach works because we know the left part of the array and the right is sorted. So if any element in the left part satisfy the condition, nums[left] > 2 * nums[right], this would apply for all the other elements of the left part as they are greater than currVal.
6. That's why, we can directly add the count of pairs for (i - 1)th element for i-th element as well. 
7. And the count we would get by adding (right - (mid + 1)) as (mid + 1) is the starting point of our right array.
*/

// Time Complexity:  O(2 * N * Log N)
// Space Complexity: O(N)
