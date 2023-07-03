#include <bits/stdc++.h> 
// Stack class.

class Stack {
vector<int> nums ;  
int cap ;

public:
    
    Stack(int capacity) 
    {
        cap = capacity ;
    }

    void push(int num) 
    {
        if(cap == nums.size() )  return ;

        nums.push_back(num) ;    
    }

    int pop() 
    {
        if(isEmpty() )  return -1 ;

        int x = nums.back() ; nums.pop_back() ;

        return x ;
    }
    
    int top() 
    {
        if(isEmpty() )  return -1 ;

        return nums.back() ;
    }
    
    int isEmpty() 
    {
        return nums.size() == 0 ? true : false ;  
    }
    
    int isFull() 
    {
        return nums.size() == cap ;
    }
    
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
