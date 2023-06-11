// LeetCode Link:  https://leetcode.com/problems/add-two-numbers/
// --------------------------------------------------------------------

/* Approach:
1. Use a dummy node to keep track of the new linked list we create. Tail pointer to create the Linked List and carry to keep track of the carry we have acquired during the addition.
2. Run a while loop till headA becomes NULL or headB becomes NULL or carry is still greater than 0.
3. We keep adding and forming the result LinkedList using the tail pointer.
4. At the end, we return dummy -> next pointing to the head of our resultant linkedList.
*/

/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node *dummy = new Node(-1) ;
    Node *tail = dummy ;

    Node *p = num1 ;  Node *q = num2 ;

    int carry = 0 ;

    while(p != NULL || q != NULL || carry > 0)
    {
        int sum = carry ;

        if(p != NULL)  
        {
            sum += p -> data ;  p = p -> next ;
        }

        if(q != NULL)  
        {
            sum += q -> data ; q = q -> next ;
        }

        Node *currNode = new Node(sum % 10) ;

        tail -> next = currNode ;  tail = currNode ;

        carry = sum / 10 ;
    }

    return dummy -> next ;
}

// Time Complexity:  O(M + M)
// Space Complexity: O(K) [ K is the length of the LinkedList we created after addition]
