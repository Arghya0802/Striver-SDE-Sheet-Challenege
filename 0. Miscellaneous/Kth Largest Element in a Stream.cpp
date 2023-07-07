// LeetCode link:  https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
// -----------------------------------------------------------------------------------------

#include <bits/stdc++.h> 
class Kthlargest {
private:
priority_queue<int , vector<int> , greater<int>> minQ ;

public:
    Kthlargest(int k, vector<int> &arr) 
    {
        for(int nums : arr)  minQ.push(nums) ;
    }

    void add(int num) 
    {
        if(minQ.top() < num)  
        {
            minQ.pop() ;  minQ.push(num) ;
        }
        
        return ;
    }

    int getKthLargest() 
    {
        return minQ.top() ;
    }

};

// Time Complexity:  O(N * Log K)
// Space Complexity: O(K)
