// LeetCode link:  https://leetcode.com/problems/intersection-of-two-linked-lists/
// --------------------------------------------------------------------------------------

/* Approach 1 [Better Approach - using Hashing]
1. Use Hashing and solve the problem in Linear Space and Time Complexity

Approach 2 [Optimal Approach - without using Hashing]
1. Initialise two dummy pointers p = headA and q = headB.
2. We run a loop till both P and Q have become NULL. It means we run till while (p != NULL or q != NULL).
3. If at any moment, p == q, we have found the intersection so we return node P or Q.
4. Otherwise, if p becomes NULL, we re-initialize it with the head of the second linked list [headB]
5. Similarly, if q becomes NULL, we re-initialize it with the head of the first linked list [headA]
6. If we get out of the for loop, it means we don't have an intersection, so we return NULL.
*/

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/

Node * findIntersection(Node *firstHead, Node *secondHead)
{
    if(firstHead == NULL || secondHead == NULL)  return NULL ;

    Node *p = firstHead ; Node *q = secondHead ;

    while(p != NULL || q != NULL)
    {
        if(p == q)  return p  ;

        if(p == NULL)  p = secondHead ;

        if(q == NULL)  q = firstHead ;

        p = p -> next ;  q = q -> next ;
    }

    return NULL ;
}

// Time Complexity:  O(2 * M) [M is the length of the longer linked list]
// Space Complexity: O(1)
