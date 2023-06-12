// LeetCode Link:  https://leetcode.com/problems/linked-list-cycle-ii/description/
// ---------------------------------------------------------------------------------

/* Approach:
1. First check if we have a cycle inside our LinkedList or not using Slow and Fast pointers.
2. If we didn't find a cycle we straight away return NULL.
3. Now, if we need to find the starting point of the Loop, we will use two pointers P & Q. P points to Head initially and Q points to Slow. 
4. The place where P & Q meets is the Starting point of the Loop. So we use a while loop for that purpose.
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

Node *firstNode(Node *head)
{
    if(head == NULL || head -> next == NULL)  return NULL ;

    if(head -> next == head)  return head ;
    
    Node *slow = head ; Node *fast = head ;

    while(fast && fast -> next)
    {
        slow = slow -> next ; fast = fast -> next -> next ;

        if(slow == fast)  break;
    }

    if(fast != slow)  return NULL ;

    Node *p = head ; Node *q = slow ;

    while(p != q)
    {
        p = p -> next ; q = q -> next ;
    }

    return p ;
}

// Time Complexity:  O(2 * N)
// Space Complexity: O(1)
