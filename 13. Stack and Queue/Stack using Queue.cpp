// LeetCode Link:  https://leetcode.com/problems/implement-stack-using-queues/description/
// --------------------------------------------------------------------------------------

#include <bits/stdc++.h> 
class Stack {
	// Define the data members.

    queue<int> Q ;

   public:
    Stack() {}

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() 
    {
        return Q.size() ;
    }

    bool isEmpty() 
    {
        return Q.size() == 0 ? true : false ;
    }

    void push(int element) 
    {
        queue<int> newQ ;

        while(!Q.empty() ) 
        {
            int top = Q.front() ;  Q.pop() ;

            newQ.push(top) ;
        }

        Q.push(element) ;

        while(!newQ.empty() )
        {
            int top = newQ.front() ;  newQ.pop() ;

            Q.push(top) ;
        }

        return ;
    }

    int pop() 
    {
        if(isEmpty() )  return -1 ;

        int x = top() ;  Q.pop() ;

        return x ;
    }

    int top() 
    {
        if(isEmpty() )  return -1 ;

        return Q.front() ;
    }
};

// Time Complexity:  O(N) for push() operation and rest is O(1) 
// Space Complexity: O(N [As we are using an external Queue]
