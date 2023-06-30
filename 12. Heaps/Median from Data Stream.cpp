// LeetCode Link:  https://leetcode.com/problems/find-median-from-data-stream/
// --------------------------------------------------------------------------

#include <bits/stdc++.h>

int findMedian(priority_queue<int> &smallQ , priority_queue<int , vector<int> , greater<int>> &largeQ)
{
    if(smallQ.size() == largeQ.size() )  return (smallQ.top() + largeQ.top() ) / 2 ;

    else if(smallQ.size() > largeQ.size() )  return smallQ.top() ;

    else return largeQ.top() ;
}

void findMedian(int arr[] , int n)
{
    priority_queue<int> smallQ ;
    priority_queue<int , vector<int> , greater<int>> largeQ ;

    for(int i = 0 ; i < n ; i++)
    {
        smallQ.push(arr[i]) ;

        if(!smallQ.empty() && !largeQ.empty() && smallQ.top() > largeQ.top() )
        {
            int x = smallQ.top() ;  smallQ.pop() ;

            largeQ.push(x) ;
        }

        int s1 = smallQ.size() ; int s2 = largeQ.size() ;

        if(s1 - s2 > 1)
        {
            int x = smallQ.top() ; smallQ.pop() ;
            
            largeQ.push(x) ;
        }

        if(s2 - s1 > 1)
        {
            int x = largeQ.top() ; largeQ.pop() ;

            smallQ.push(x) ;
        }

        int median = findMedian(smallQ , largeQ) ;

        cout << median << " " ;
    }

    cout << endl ;
}

// Time Complexity:  O(N * Log N)
// Space Complexity: O(2 * N) [As we are using 2-Heaps]
