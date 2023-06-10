// LeetCode Link:  https://leetcode.com/problems/middle-of-the-linked-list/description/
// ---------------------------------------------------------------------------------------

/* Approach [Slow and Fast Pointers]
1. To find the Middle Node of a LinkedList, we use Slow and Fast pointers.
2. Make the Fast pointer move by a distance of 2 while the Slow pointer moves as a single node
3. The concept is that our Slow pointer will be in the Middle Node of the LinkedList when our fast pointer becomes NULL.
4. We need to ensure that we don't encounter a NULL pointer exception that's why we traverse till we have traversed the entire LinkedList( Fast = NULL) or we are the last node (Fast -> next = NULL). This happens for Even and Odd number of nodes respectively.
*/

/*
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
*/

Node *findMiddle(Node *head) 
{
    Node *slow = head ;  Node *fast = head ;

    while(fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next ;

        fast = fast -> next -> next ;
    }

    return slow ;
}

// Time Complexity:  O(N)
// Space Complexity: O(1)
