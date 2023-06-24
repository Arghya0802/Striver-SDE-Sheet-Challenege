// LeetCode Link:  https://leetcode.com/problems/top-k-frequent-elements/description/
// ---------------------------------------------------------------------------------

// Simple Priority Queue [Min-Heap] Solution

#include <bits/stdc++.h> 
using pp = pair<int , int> ;

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int , int> hashMap ;
            
    for(auto it : arr)  hashMap[it]++ ;

    priority_queue<pp , vector<pp> , greater<pp>> minHeap ;

    for(auto &x : hashMap)
    {
        int val = x.first ; int freq = x.second ;

        if(minHeap.size() < k)  minHeap.push({freq , val}) ;

        else if(freq > minHeap.top().first ) 
        {
            minHeap.pop() ; minHeap.push({freq , val}) ;
        }
    }

    vector<int> ans ;

    while(k--)  
    {
        ans.push_back(minHeap.top().second) ;  minHeap.pop() ;
    }

    sort(ans.begin() , ans.end() ) ;
    
    return ans ;
}

// Time Complexity:  O(N * Log K) [Ignoring the sorting at the end because its question specific]
// Space Complexity: O(K)
