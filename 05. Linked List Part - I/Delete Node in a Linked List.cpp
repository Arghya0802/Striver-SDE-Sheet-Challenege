// LeetCode Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
// ------------------------------------------------

/* Approach:-
1. Swap the values of the given Node and the Node's Next Node
2. Store the reference to Node's next node, which is the node we need to delete now in the delNode pointer.
3. Make our node -> next point to node -> next -> next. This will help to form the new links.
4. At the end, we delete delNode before returning.
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

void deleteNode(LinkedListNode<int> * node) 
{

    swap(node -> data , node -> next -> data) ;

    LinkedListNode <int> *delNode = node -> next ;

    node -> next = node -> next -> next ;

    delete(delNode) ;

    return ;
}

// Time Complexity:  O(1)
// Space Complexity: O(1)
