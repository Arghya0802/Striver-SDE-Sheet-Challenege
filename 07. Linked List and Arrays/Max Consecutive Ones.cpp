// LeetCode Link:  https://leetcode.com/problems/max-consecutive-ones/
// -------------------------------------------------------------------

/* Approach [Sliding Window Variable Size]
1. As we can flip at most K 0's. we can use a sliding window to keep track and count the length of the maximum window valid. 
*/

int longestSubSeg(vector<int> &arr , int n, int k)
{
    int end = 0 ;  int cnt = 0 ;  int maxCnt = 0 ;

    for(int start = 0 ; start < n ; start++)
    {
        if(arr[start] == 0)  cnt++ ;

        while(end <= start && cnt > k)
        {
            if(arr[end] == 0)  cnt-- ;   

            end++ ;
        }

        maxCnt = max(maxCnt , start - end + 1) ;
    }

    return maxCnt ;
}

// Time Complexity:  O(N)
// Space Complexity: O(1)
