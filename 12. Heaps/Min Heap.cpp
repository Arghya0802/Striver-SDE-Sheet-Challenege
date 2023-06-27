#include <bits/stdc++.h> 

void insertToHeap(int x , vector<int> &arr)
{
    arr.push_back(x) ;  int n = arr.size() ;
    int ind = arr.size() - 1 ;

    while(ind > 1)
    {
        int parent = ind / 2 ;

        if(arr[parent] > arr[ind] )
        {
            swap(arr[parent] , arr[ind] ) ;  
            ind = parent ;
        }

        else return ;
    }
}

int deletFromHeap(vector<int> &arr)
{
    int n = arr.size() ;

    if(n == 1)  return -1 ;

    int x = arr[1] ;  

    arr[1] = arr.back() ; arr.pop_back() ; n-- ;
    
    if(n == 1)  return x ;

    int root = 1 ;  

    while(root < arr.size() )
    {
        int leftIndex = 2 * root ;  int rightIndex = 2 * root + 1 ;
        int swapIndex = root ;

        if(leftIndex < arr.size()  && arr[leftIndex] < arr[root] )  swapIndex = leftIndex ;

        if(rightIndex < arr.size()  && arr[rightIndex] < arr[swapIndex] )  swapIndex = rightIndex ;

        if(swapIndex != root)
        {
            swap(arr[swapIndex] , arr[root]) ;  root = swapIndex ;
        }

        else return x ;
    }

    return x ;
}

vector<int> minHeap(int n, vector<vector<int>>& q) 
{
    vector<int> ans ; 
    vector<int> heap ;  heap.push_back(-1) ;

    for(auto query: q)
    {
        
        if(query[0] == 0)  
        {
            // cout << query[1] << endl ;
            insertToHeap( query[1] , heap) ;
        }

        else
        {
            // if(maxQ.top() == INT_MIN)  continue ;

            int val = deletFromHeap(heap) ; 

            if(val != -1)  ans.push_back(val) ;
        }
    }

    return ans ;
}

// Time Complexity:  O(Q * LogN)
// Space Complexity: O(N)
