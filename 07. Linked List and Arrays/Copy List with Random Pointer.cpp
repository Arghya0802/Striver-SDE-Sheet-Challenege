// LeetCode Link:  https://leetcode.com/problems/copy-list-with-random-pointer/description/
// ----------------------------------------------------------------------------------------

/* Approach:
1. We can solve this question using Hashing.
2. As we are making a deep copy of every node, so we need to ensure every node's random point to its correct deep copy and not anyone else.
3. To ensure this, we first create a copy of all the nodes of the given LinkedList and map them with their old ones like- 
                                             map[p] = copy; 
Here, p is the old node while copy is the new node we have just created.
4. Next we traverse over the LinkedList again, and this time instead of creating a new Node, we get the nodes we have already created using our hashMap.
                                   Node *copy = map[p]; // Gives the copy of the Current Old Node
                                   Node *copyRand = map[p -> random]; // Get the deep copy of the node to which the old node's random pointer points.
                                   copy -> random = copyRand; // We make the new copy random point to the new randCopy

5. At the end, we return dummy -> next as usual.
*/

// Time Complexity:  O(N)
// Space Complexity: O(2 * N) [N for creating new nodes and N for storing all the deep copies inside our HashMap]
