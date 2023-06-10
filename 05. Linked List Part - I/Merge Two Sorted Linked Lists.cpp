// LeetCode Link: https://leetcode.com/problems/merge-two-sorted-lists/description/
// -----------------------------------------------------------------------------------

/* Approach [Same as Merge Two-Sorted Arrays]
1. The approach to the problem remains exactly the same as we merge two sorted arrays except we don't need to create another LinkedList. We can modify the links given to us already!!
2. We create a dummy node as -1 and Tail Pointer pointing to it initially,
3. Every time we check if First Node's val < Second Node's val or not. If true, we make tail -> next = First; tail = First; and move  First to its next node.
4. Else, we make tail -> next = Second; tail = Second; and Second to its next node.
5. Before returning, we need to make sure we include all the rest nodes of the First or Second list.
6. At the end, we return dummy -> next.
*/

#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL && second == NULL)  return NULL ;

    if(first == NULL)   return second ;
    if(second == NULL)  return first ;

    Node <int> *dummy = new Node <int> (-1) ;
    Node <int> *tail = dummy ;

    Node<int> *p = first ;  Node <int> *q = second ;

    while(p != NULL && q != NULL)
    {
        if(p -> data < q -> data)
        {
            tail -> next = p ;  tail = p ;

            p = p -> next ;
        }

        else
        {
            tail -> next = q ;  tail = q ;

            q = q -> next ;
        }
    }

    if(p == NULL)  tail -> next = q ;

    else tail -> next = p ;

    return dummy -> next ;
}

// Time Complexity:  O(M + N)
// Space Complexity: O(1) 
