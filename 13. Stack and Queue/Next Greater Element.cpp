// LeetCode Link:  https://leetcode.com/problems/next-greater-element-i/
// --------------------------------------------------------------------

#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) 
{
    vector<int> ans(n , -1) ;

    stack<int> st ;  st.push(arr.back() ) ;

    for(int i = n - 2 ; i >= 0 ; i--)
    {
        int val = arr[i] ;

        while(!st.empty() && val >= st.top() )  st.pop() ;

        if(!st.empty() )  ans[i] = st.top() ;

        st.push(val) ;
    }

    return ans ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
