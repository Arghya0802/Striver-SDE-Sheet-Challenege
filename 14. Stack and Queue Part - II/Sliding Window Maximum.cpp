// LeetCode Link:  https://leetcode.com/problems/sliding-window-maximum/
// ----------------------------------------------------------------------

#include <bits/stdc++.h> 

vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    int n = nums.size() ;

    vector<int> ans ;  deque<int> dq ;

    for(int i = 0 ; i < n ; i++)
    {
        if(!dq.empty() && i - dq.front() == k)  dq.pop_front() ;

        while(!dq.empty() && nums[i] >= nums[ dq.back() ] ) dq.pop_back() ;

        dq.push_back(i) ;

        if(i >= k - 1)  ans.push_back(nums[ dq.front() ]) ;
    }

    return ans ;
}

// Time Complexity:  O(N)
// Space Complexity: O(K)
