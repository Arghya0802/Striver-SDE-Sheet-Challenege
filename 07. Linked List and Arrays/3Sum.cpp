// LeetCode Link: 
// -----------------------------------------------------------

/* Approach:
1. Sort the array or vector nums[] and declare a 2D ans[][] vector.
2. Start a for loop from i = 0 till N
3. Use 2-pointers to get our target which is K - nums[i]
4. Low = i + 1 and High = n - 1 ;
5. If at any moment, our sum becomes equal to our target, we push the 3-numbers inside our ans [][] vector.
6. To skip duplicates we use, while(i + 1 < n && nums[i] == nums[i + 1) i++; 
*/

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(1)
