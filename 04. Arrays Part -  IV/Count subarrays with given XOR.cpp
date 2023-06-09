// Link: https://www.interviewbit.com/problems/subarray-with-given-xor/
// ----------------------------------------------------------------------

/* Approach [Exactly same as Subarray Sum Equals K]
1. The approach to the problem remains exactly the same as finding the Max Length of the subarray whose sum is K.
2. Instead of using prefixSum. we would be using prefXOR here. 
3. We just need to increment our ans by hashMap[prefXOR ^ K] if we have it inside our hashMap and increment the count of hashMap[prefXOR] by 1 at every stage.
*/

// Time Complexity:  O(N)
// Space Complexity: O(N)
