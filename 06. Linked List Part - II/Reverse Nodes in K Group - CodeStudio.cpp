/* Approach [CodeStudio]
A) For the CodeStudio problem, we will have blocks of windows of different sizes decided by the array b[].
B) For b[i] = 0, we don't need to do anything.
C) If at any point, we have a block of nodes < b[i], we need to reverse that block of node as a whole.
D) The approach remains the same, but we need to take care of the extra edge cases that's all.
*/

#include <bits/stdc++.h> // I have given the Iterative code only. The recursive code remains the same still

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *reverseLL(Node *start , Node *end) // Reverses the LinkedList from [start, end]
{
	Node *curr = start ; Node *prev = NULL ; Node *last = NULL ;

	while(prev != end)
	{
		last = prev ;  prev = curr ;

		curr = curr -> next ;  prev -> next = last ;
	}

	return prev ;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[])
{
  // Cnt is used to count the number of nodes we have traversed in total, while Prev is used to count the size of the current block of nodes
	int cnt = 0 ; int prev = 0 ;  int i = 0 ; 

	Node *dummy = new Node(-1) ;  dummy -> next = head ;
	
	Node *beforeStart = dummy ; Node *end = head ;	

	while(end != NULL && i < n) // We need to ensure we traverse nodes and also don't get out of the array B[]
	{
		while(i < n && b[i] == 0)  i++ ; // We have to skip B[i] == 0

		cnt++ ;

		if(cnt - prev == b[i]) // We have traversed a block of code which equals B[i]
		{
			
			Node *nextNode = end -> next ;  Node *start = beforeStart -> next ;

			reverseLL(start , end) ;

			beforeStart -> next = end ;  beforeStart = start ;
			
			start -> next = nextNode ; end = nextNode ;  
			
			prev = cnt ; i++ ;
		}

		else  end = end -> next ;
	}

	// We have some nodes left to be reversed which are less than B[i]
	if(i < n)
	{
    // This reversal reverses the remaining nodes from beforeStart -> next till the Last Node
		Node *curr = beforeStart -> next ; Node *prev = NULL ; Node *last = NULL ;

		while(curr != NULL)
		{
			last = prev ; prev = curr ;

			curr = curr -> next ; prev -> next = last ;
		}

		beforeStart -> next = prev ; // Before returning, we need to ensure that beforeStart -> next points to the head of the reversed block
	}

	return dummy -> next ;
}

// Time Complexity:  O(N)
// Space Complexity: O(1) 
