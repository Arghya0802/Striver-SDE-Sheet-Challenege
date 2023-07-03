#include <bits/stdc++.h>
class Queue {
    // Define the data members(if any) here.
     
    stack<int> st ;

    public:
    Queue() {}

    void enQueue(int val) 
    {
        st.push(val) ;  return ;
    }

    int deQueue() 
    {
        if(isEmpty() )  return -1 ;

        stack<int> newStack ;

        while(!st.empty() )
        {
            newStack.push(st.top() ) ;  st.pop() ;
        }

        int x = newStack.top() ;  newStack.pop() ;

        while(!newStack.empty() )
        {
            st.push(newStack.top() ) ; newStack.pop() ;
        }

        return x ;
    }

    int peek() 
    {
        if(isEmpty() )  return -1 ;

        stack<int> newStack ;

        while(!st.empty() )
        {
            newStack.push(st.top() ) ;  st.pop() ;
        }

        int x = newStack.top() ;  

        while(!newStack.empty() )
        {
            st.push(newStack.top() ) ; newStack.pop() ;
        }

        return x ;
    }

    bool isEmpty() 
    {
        return st.size() == 0 ? true : false ;
    }
};

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N)
