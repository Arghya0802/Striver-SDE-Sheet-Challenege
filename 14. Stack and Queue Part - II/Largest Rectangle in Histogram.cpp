// LeetCode Link: https://leetcode.com/problems/largest-rectangle-in-histogram/
// ----------------------------------------------------------------------------

#include<bits/stdc++.h>

vector<int> nextGreaterRight(vector<int> &arr , int n)
{
    stack<pair<int, int>> st ;  vector<int> v ;

      for (int i = n - 1 ; i >= 0 ; i--) 
      {
        if (st.empty() )   v.push_back(n) ;

        else if (!st.empty()&& arr[i] > st.top().first)  v.push_back(st.top().second) ;

        if(!st.empty() && arr[i] <= st.top().first )
        {
            while (!st.empty() && arr[i] <= st.top().first)  st.pop() ;

            if (!st.empty() )   v.push_back(st.top().second) ;
          
            else v.push_back(n );
        }

        st.push(make_pair(arr[i], i) ) ;

      }

    
    reverse(v.begin(), v.end() ) ;

    return v ;
}

vector<int> nextSmallerLeft(vector<int> &arr , int n)
{
    stack<pair<int, int>> st ;  vector<int> v ;

    for (int i = 0 ; i < n ; i++) 
    {
        if (st.empty() )  v.push_back(-1);

        else if (!st.empty() && st.top().first < arr[i] )  v.push_back(st.top().second) ;

        else if (!st.empty() && st.top().first >= arr[i]) 
        {
            while (!st.empty() && st.top().first >= arr[i]) st.pop() ;

            if (!st.empty() )  v.push_back(st.top().second) ;

            else v.push_back(-1) ;
        }

        st.push(make_pair(arr[i], i) ) ;

    }

    return v ;
}
 
 int largestRectangle(vector < int > & arr) 
 {
    int n = arr.size() ;   vector<int> width(n) ; int maxArea = 0 ;

    vector<int> left = nextSmallerLeft(arr , n) ; 

    vector<int> right = nextGreaterRight(arr , n) ;

    for (int i = 0 ; i < n ; i++) width[i] = right[i] - left[i] - 1 ;

    for (int i = 0 ; i < n ; i++) 
    {
      int area = width[i] * arr[i] ;  maxArea = max(maxArea, area) ;

    }
    
    return maxArea;

 }

// Time Complexity:  O(N)
// Space Complexity: O(N)
