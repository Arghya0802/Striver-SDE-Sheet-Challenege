// GFG Link:  https://practice.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1
// -----------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>

vector<int> maxMinWindow(vector<int> &a, int n) 
{
    stack<int> st ;

    vector<int> left(n + 1 , -1) ;  vector<int> right(n + 1 , n) ;

    for (int i = 0 ; i < n ; i++) 
    {
        while (!st.empty() && a[st.top()] >= a[i])  st.pop() ;
        
        if (!st.empty() )  left[i] = st.top() ;
        
        st.push(i);
    }

    while (!st.empty() )  st.pop() ;

    for (int i = n - 1 ; i >= 0 ; i--) 
    {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop() ;
        
        if (!st.empty() )  right[i] = st.top();
        
        st.push(i);
    }

    vector<int> ans(n + 1 , INT_MIN) ;  vector<int> res(n) ;

    for (int i = 0 ; i < n ; i++) 
    {
        int len = right[i] - left[i] - 1 ; 
                                            
        ans[len] = max(ans[len] , a[i]) ;
    }

    for (int i = n - 1 ; i >= 1 ; i--)  ans[i] = max(ans[i] , ans[i + 1]) ;

    for (int i = 1 ; i <= n ; i++)  res[i - 1] = ans[i] ;

    return res ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
