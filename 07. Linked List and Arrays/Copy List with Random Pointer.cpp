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

#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    unordered_map<LinkedListNode <int> *, LinkedListNode <int> *> nodesMap ;

    LinkedListNode <int> *p = head ;

    while(p != NULL)
    {
        LinkedListNode <int> *copy = new LinkedListNode <int> (p -> data) ;

        nodesMap[p] = copy ; p = p -> next ;
    }

    LinkedListNode <int> *dummy = new LinkedListNode <int> (-1) ;  
    LinkedListNode <int> *tail = dummy ;

    p = head ;

    while(p != NULL)
    {
        LinkedListNode <int> *copy = nodesMap[p] ;
        
        LinkedListNode <int> *randCopy = nodesMap[p -> random] ;

        tail -> next = copy ; tail = copy ;

        copy -> random = randCopy ;  

        p = p -> next ;
    }

    return dummy -> next ;
}


// Time Complexity:  O(N)
// Space Complexity: O(2 * N) [N for creating new nodes and N for storing all the deep copies inside our HashMap]
