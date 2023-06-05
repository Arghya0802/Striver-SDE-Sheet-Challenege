// LeetCode Link: https://leetcode.com/problems/merge-intervals/
// -------------------------------------------------------------------------

/* Approach: Greedy 
1. Sort the 2D vector according to the starting Points
2. Initially take start = nums[0][0] and end = nums[0][1] .
3. Run a loop from i = 1 till n and check if the current Start-Point falls inside our already assumed start and end.
4. More formally check, If nums[i][0] >= start and nums[i][[1] <= end, it means we have an overlapping interval.
5. So, we increment our interval range by updating the start as min(start, nums[i][0]) and end as max(end, nums[i][1]). This is to ensure our start is closest to the origin and end is farthest away possible so we include more and more ranges.
6. If not, we don't have an overlapping interval, so we push {start, end} inside our 2D ans[][] vector and reinitialise them to current start and end points

*/

#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size() ;
    
    vector<vector<int>> ans ;

    sort(intervals.begin() , intervals.end() ) ;

    int start = intervals[0][0] ;  int end = intervals[0][1] ;

    for(int i = 1 ; i < n ; i++)
    {
        int newSt = intervals[i][0] ; int newEnd = intervals[i][1] ;

        if(newSt >= start && newSt <= end)
        {
            start = min(start ,newSt) ;  end = max(end , newEnd) ;
        }

        else
        {
            ans.push_back({start , end}) ;

            start = newSt ; end = newEnd ;
        }
    }

    ans.push_back({start , end}) ;

    return ans ;
}
/*
Time Complexity:  O(N * LogN) [For sorting the vector]
Space Complexity: O(N) [For our ans[][] vector]
*/
