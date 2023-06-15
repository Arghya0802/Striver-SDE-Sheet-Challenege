// GFG Link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
// ------------------------------------------------------------------------------------

/* Approach [Greedy]
1. We sort both the arrival and departure times array. We don't bother about which train arrives when and which leaves when because we are only concerned about the max number of platforms we require to handle the arrival and departures of trains.
2. We keep a pointer j = 0, and start our iteration from i = 1. MaxCnt = 1 and Cnt = 1 are also initialized.  
3. For every arrival of the train, we check if any of the previous platforms might become vacant or not. We use a while loop for doing so and decrement our cnt by 1.
4. At the exit of the while loop, we increment our cnt by 1 for the current platform and update our maxCnt as max(maxCnt, cnt).
*/

int calculateMinPatforms(int at[], int dt[], int n) 
{
    sort(at , at + n) ;  sort(dt , dt + n) ;

    int maxCnt = 1 ; int cnt = 1 ; int j = 0 ;

    for(int i = 1 ; i < n ; i++)
    {
        if(j ==  n) break ;

        while(j < n && dt[j] < at[i])  
        {
            j++ ; cnt-- ;
        }

        cnt++ ; 

        maxCnt = max(maxCnt , cnt) ;
    }

    return maxCnt ;
}

// Time Complexity:  O(N * Log N)
// Space Complexity: O(1)
