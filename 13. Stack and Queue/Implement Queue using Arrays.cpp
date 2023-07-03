#include <bits/stdc++.h> 
class Queue {
private:
vector<int> Q ;

public:
    Queue() {}

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() 
    {
        return Q.size() == 0 ? true : false ;
    }

    void enqueue(int data) 
    {
        Q.push_back(data) ;  return ;
    }

    int dequeue() 
    {
        if(isEmpty() )  return -1 ;

        int x = Q[0] ;
        
        reverse(Q.begin() , Q.end() ) ;  Q.pop_back() ;

        reverse(Q.begin() , Q.end() ) ;

        return x ;
    }

    int front() 
    {
        if(isEmpty() )  return -1 ;

        return Q[0] ;
    }
};

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N)
