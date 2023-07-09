#include <bits/stdc++.h> 

void insertAtPlace(int x , stack<int> &st)
{
	if(st.empty() || x > st.top() )  
	{
		st.push(x) ;  return ;
	}

	int val = st.top() ;  st.pop() ;

	insertAtPlace(x , st) ;

	st.push(val) ;
}

void sortStack(stack<int> &stack)
{
	if(stack.empty() || stack.size() == 1)  return ;	

	int x = stack.top() ;  stack.pop() ;
	
	sortStack(stack) ;

	insertAtPlace(x , stack) ;

	return ;
}

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N) [Recursive Stack Space is used only]
