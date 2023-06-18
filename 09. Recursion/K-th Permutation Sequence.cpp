// LeetCode Link: https://leetcode.com/problems/permutation-sequence/description/
// -----------------------------------------------------------------------------

/* Approach [Typical Algorithmic question]
1. We need to return the K-th permutation from 1 to N, but as N can be equal to 9, we cannot generate all the possible permutations.
2. We need to use a particular algorithm to solve the question.
3. We first push all the numbers from 1 to N inside vector nums[] and calculate till (N - 1)! and store it inside the Fact variable. We decrement K by 1 as we follow 0-based indexing
4. The index of the current element of our K-th Permutation Sequence is K / Fact.
5.  To get the rest of the digits, we decrement K as K % Fact and decrement Fact as Fact /= nums.size() [we move to (N - 2)! and so on]
6. We break out of the loop, whenever our nums become empty or nums.size() equals 0.
*/

// Time Complexity:  O(N ^ 2) [To iterate over all the elements once and delete the element after we have taken it]
// Space Complexity: O(N) [We have taken extra nums[] vector]
