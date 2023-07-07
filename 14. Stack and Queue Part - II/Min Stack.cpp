// LeetCode link:  https://leetcode.com/problems/min-stack/description/
// -------------------------------------------------------------------

#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	stack<int> st ;  
	stack<int> minStck ;

	public:
		
		// Constructor
		minStack() {}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			st.push(num) ;

			if(minStck.empty() )  minStck.push(num) ;

			else if(minStck.top() >= num)  minStck.push(num) ;

			return ;
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			if(st.empty() )  return -1 ;

			int x = top() ;  st.pop() ; 

			if(x == minStck.top() )  minStck.pop() ;

			return x ;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			if(st.empty() )  return -1 ;

			return st.top() ;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			if(minStck.empty() )  return -1 ;

			return minStck.top() ;
		}
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
