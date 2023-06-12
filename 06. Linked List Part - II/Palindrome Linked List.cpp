// LeetCode Link: https://leetcode.com/problems/palindrome-linked-list/
// --------------------------------------------------------------------

/* Approach:
1. Reverse the LinkedList from the middle and simultaneously check if the LinkedList is palindrome or not.
2.  By reversing the LinkedList in the middle, we can use two pointer technique to check if the LinkedList is a palindrome or not without using extra space.
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

LinkedListNode <int> *reverseLL(LinkedListNode <int> *head)
{
	LinkedListNode <int> *curr = head , *prev = NULL , *last = NULL ;

	while(curr != NULL)
	{
		last = prev ;  prev = curr ;

		curr = curr -> next ;

		prev -> next = last ;
	}

	return prev ;
}
bool isPalindrome(LinkedListNode<int> *head) 
{
    if(head == NULL || head -> next == NULL)  return true ;

    LinkedListNode <int> *prev = NULL , *slow = head , *fast = head ;

    while(fast && fast -> next)
    {
        prev = slow ; slow = slow -> next ;

        fast = fast -> next -> next ;
    }

    prev -> next = NULL ;

    LinkedListNode <int> *rev = reverseLL(slow) ;

    LinkedListNode <int> *p = head , *q = rev ;

    while(p && q)
    {
        if(p -> data != q -> data)  return false ;

        p = p -> next ; q = q -> next ;
    }

    return true ;
}

// Time Complexity:  O(3 * N)
// Space Complexity: O(1)

