// GFG Link: 
// -----------------------------------------------------------------------

/* Approach [Same as N meetings in One Room]
1. The approach is exactly similar to N meetings in the One Rom problem - we need to return the count of activities in place of the order in which they are performed.
2. One thing which is different is that- we can start an activity immediately after finishing another activity so our condition becomes 
                                             if(startTime >= maxFinishTime)  {
                                                       maxCnt++ ; 
                                                       maxFinishTime = newEndTime ;
                                            }
 */

#include<bits/stdc++.h>
using pp = pair<int , int> ;

int maximumActivities(vector<int> &start, vector<int> &finish) 
{
    int n = finish.size() ;

    vector<pp> nums ;

    for(int i = 0 ; i < n ; i++)  nums.push_back( {finish[i] , start[i]} ) ;    

    sort(nums.begin() , nums.end() ) ;
    
    int maxAct = 1 ;  int finishTime = nums[0].first ;

    for(int i = 1 ; i < n ; i++)
    {
        int startTime = nums[i].second ;

        if(startTime >= finishTime)
        {
            maxAct++ ; finishTime = nums[i].first ;
        }
    }

    return maxAct ;
}

// Time Complexity:  O(N * Log N)
// Space Complexity: O(N)
