// LeetCode Link: https://leetcode.com/problems/reverse-linked-list/description/
// ----------------------------------------------------------------------

/* Approach:
1. Use 3-pointers curr, prev and last.
2. Initialise curr = head; prev = last = NULL.
3. Start a while loop till curr != NULL. Make last come to prev and prev come to curr,
4. Move curr to the next node.
5. To reverse the connection, we use this trick- prev -> next = last ;
*/

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode <int> *curr = head ;
    LinkedListNode <int> *prev = NULL ; 
    LinkedListNode <int> *last = NULL ;

    while(curr != NULL)
    {
        last = prev ;  prev = curr ;

        curr = curr -> next ;

        prev -> next = last ;
    }

    return prev ;

}
