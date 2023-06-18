// LeetCode Link:  https://leetcode.com/problems/palindrome-partitioning/description/
// ----------------------------------------------------------------------------------

/* Approach [Recursion]
1. As we need to generate all possible palindromic partitions, we need to use Recursion & Backtracking.
2. We start from i = index till i < s.size() and calculate all the prefixes possible inside the For loop.
3. After that, we check whether the current prefix is Palindromic or not.
4. If true, we include the prefix inside our container[] vector and ask recursion to do the rest of the task.
5. After the recursion call has returned, we have to backtrack and undo the change- remove the prefix string from our container[] so that don't include it in other possible partitioning sequences.
*/

// Time Complexity:  O(2 ^ N * N / 2) [2 ^ N is to generate all the substrings, N / 2 is to check if they are Palindrome or not]
// Space Complexity: O(N) [Recursive Stack Space & Ignoring space taken ans[][] and Container vectors respectuvely] 
