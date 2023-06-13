// LeetCode Link:  https://leetcode.com/problems/reverse-nodes-in-k-group/description/
// -----------------------------------------------------------------------------------

/* Approach [LeetCode] 
A) The LeetCode version is easier than the CodeStudio because in LeetCode the length of each block is fixed and for blocks of nodes less than K, we don't need to reverse them at all. 
B) The Recursive and Iterative approaches are quite similar, one uses extra stack space while the other doesn't use any space at all.

1. We initialize a dummy pointer so that we keep track of our reversed linked list. And a beforeStart pointer to establish the link between the previous block and the current block. Make sure the dummy's next points to the Head of the LinkedList. Use an end pointer to traverse the entire LinkedList and a cnt to keep track of the block of codes we have traversed.
2. When our cnt % K == 0, it means we have crossed a block of size K, so we perform our reversal task- start begins from beforeStart's next node, we store the next node in nextNode variable and call reverseLL(start, end) function which reverses the LinkedList beginning from [start, end] inclusive.
3. After the reversal, our start becomes the last node of the block and the end becomes the head of the block. We make connections as 
                                      beforeStart -> next = end ;
                                      start -> next = nextNode ;
                                      beforeStart = start; // For next block of nodes
                                      end = nextNode ;

4.  Else if we haven't hit a block of nodes of size K, we move ur end pointer to its next node.
5. At the end, we return dummy -> next.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:

ListNode *reverseLL(ListNode *start , ListNode *end)
{
    ListNode *curr = start ; ListNode *prev = NULL ; ListNode *last = NULL ;

    while(prev != end) // We need to reverse all the nodes including [start , end]
    {
        last = prev ; prev = curr ;

        curr = curr -> next ;  prev -> next = last ;
    } 

    return prev ;
}

ListNode *revKGroup(ListNode *head , int k) // Recursive approach using Recursive Stack Space
{
    if(!head || !head -> next || k == 1)  return head ;    

    ListNode *start = head ; ListNode *end = head ;

    for(int i = 0 ; i < k - 1 ; i++)  
    {
        end = end -> next ;

        if(end == NULL)  return start ; // If we don't have K nodes left, we leave them as it is
    }

    ListNode *recur = reverseKGroup(end -> next , k) ;

    reverseLL(start , end) ; // After reversing, start goes at the back, while end becomes head

    start -> next = recur ;

    return end ;
}

public:
    ListNode* reverseKGroup(ListNode* head, int k) // Recursive approach
    {
        if(!head || !head -> next || k == 1)  return head ; 

        // return revKGroup(head , k) ;

        // Iterative approach will be same as Recursive one - we need to use a dummy pointer first

        ListNode *dummy = new ListNode(-1) ;  dummy -> next = head ;

        ListNode *beforeStart = dummy ; // Helps to make connections bewtween diff Blocks 
        
        ListNode *end = head ;

        int cnt = 0 ; // Used to count the number of nodes we have seen till now

        while(end != NULL)
        {
            cnt++ ;

            if(cnt % k == 0) // We have crossed a Block of size K
            {
                ListNode *nextNode = end -> next ;  // Helps to move the end to it's next node

                // We start from the node just after beforeStart
                ListNode *start = beforeStart -> next ; 

                // On reversing, start moves to the end, while end becomes head of the block of Nodes
                reverseLL(start , end) ;

                beforeStart -> next = end ; // Ensuring connection between Prev and Current Block

                start -> next = nextNode ; // Ensuring connection between Current and Next Block

                beforeStart = start ;  end = nextNode ;
            }

            else  end = end -> next ;
        }

        // In Iterative version, if we have nodes < K, if condition will fail and they won't be reversed at all

        return dummy -> next ;
    }
};

/* 
For Recursive Code:
Time Complexity:  O(N)
Space Complexity: O(N) [Recursive Stack Space]


For Iterative Code:
Time Complexity:  O(N)
Space Complexity: O(1)
*/ 
