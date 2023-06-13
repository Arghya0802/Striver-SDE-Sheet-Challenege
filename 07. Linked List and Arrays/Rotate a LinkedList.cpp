// LeetCode Link: https://leetcode.com/problems/rotate-list/description/
// ----------------------------------------------------------------------

/* Approach 1 [Using Extra Space]:
1. The Approach is very simple. We count the nodes N at first, reduce K to K % N, and since we have to right rotate, so we do (N - K) left rotations to do exactly the same. 
2. The extra space is used to store all the elements of the node inside a vector nums[] and we use the Reversal Algorithm to reverse (N - K) elements of the LinkedList.
3. Before returning, we need to place the values back into our LinkedList and return its head.

Approach 2[ [Without using Extra Space]:
1. In this approach also, we first need to count the number of nodes N, reduce K to K % N, and in place of right-rotating K elements, we will left-rotate (N - K) elements.
2. However, instead of using an extra array, we can observe that if we left-rotate (N - K) elements and consider 1-based indexing, the element at (N - K) becomes our end Node, i.e points to NULL, and its next node becomes our head node.
3. So we run a loop for (N - K - 1) times, reach the Last Node of our new LinkedList, store its Next Node first into a rotate pointer, and then make its next point NULL. 
4. At the end, we return rotate which is the head of our rotated linkedList.
*/

// Time Complexity:  O(N)
// Space Complexity: O(N)
