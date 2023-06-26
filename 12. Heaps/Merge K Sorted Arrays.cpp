#include <bits/stdc++.h> 

using pp = pair<int , pair<int , int> > ;

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<pp , vector<pp> , greater<pp>> minHeap ;
     
    vector<int> ans ;

    for(int i = 0 ; i < k ; i++) minHeap.push({ kArrays[i][0] , {0 , i }}) ;

    while(!minHeap.empty() )
    {
        auto top = minHeap.top() ;  minHeap.pop() ;

        int val = top.first ;  int i = top.second.first ; int ind = top.second.second ;

        ans.push_back(val) ;
        
        if(i + 1 < kArrays[ind].size() )  minHeap.push({ kArrays[ind][i + 1] , {i + 1 , ind } }) ;
    }


    return ans ;

}

// Time Complexity:  O(N * Len * Log K) [N is the size of kArrays and Len is the avg length of of each array in kArrays]
// Space Complexity: O(N) [At every momemt, we will have N elements inside our Heap]
