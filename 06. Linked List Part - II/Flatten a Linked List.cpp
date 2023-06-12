// GFG Link:  https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
// --------------------------------------------------------------------------------------

/* Approach:
1. Similar to Merging Two LinkedLists but instead of two- we have been given the head of N sorted LinkedLists.
2. We use recursion to merge only two and ask recursion to merge the rest of them. 

PS: The approach was very simple, but in CodeStudio faced some error which was not present in the GFG compiler.
*/

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node *mergeLinkedLists(Node *headA , Node *headB)
{
	Node *dummy = new Node(-1) ;
	Node *tail = dummy ;

	Node *p = headA ;  Node *q = headB ;

	while(p != NULL && q != NULL)
	{
		if(p -> data < q -> data)
		{
			tail -> child = p ; tail = p ;
			
			p = p -> child ;
		}

		else
		{
			tail -> child = q ; tail = q ;

			q = q -> child ;
		}
	}

	if(p == NULL)  tail -> child = q ;

	else  tail -> child = p ;

	return dummy -> child  ;
}

Node* flattenLinkedList(Node* head) 
{
	if(head == NULL || head -> next == NULL)  return head ;

	Node *root = head -> next ;

	head -> next = NULL ;

	root = flattenLinkedList(root) ;

	Node *ans = mergeLinkedLists(head , root) ;

	return ans ;
}

// Time Complexity:  O(N * N * K) [K is the average length of each Sorted Child Linked List]
// Space Complexity: O(N) [Recursive Stack Space]
