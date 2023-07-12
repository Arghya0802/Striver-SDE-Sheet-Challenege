// LeetCode link:  https://leetcode.com/problems/online-stock-span/description/
// ----------------------------------------------------------------------------

#include <bits/stdc++.h> 

vector<int> findSpans(vector<int> &price) 
{
    int n = price.size() ;  vector<int> ans ;

    stack<pair<int , int>> st ;

    for(int i = 0 ; i < n ; i++)
    {
        int cnt = 1 ;

        while(!st.empty() && price[i] >= st.top().first)
        {
            cnt += st.top().second ;  st.pop() ;
        }

        ans.push_back(cnt) ;  

        st.push(make_pair(price[i] , cnt) ) ;
    }

    return ans ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
