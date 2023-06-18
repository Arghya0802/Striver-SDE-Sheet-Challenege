// GFG Link:  https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
// -------------------------------------------------------------------------------------------

/* Approach [Greedy + Sorting]
1. To get the maximum profit, we need to sort the Jobs[] array based on descending order of Profits.
2. Now, to maximize our profit, we would solve a given task as close to its deadline as possible (ideally we would like to solve it on D-Day only)
3. Thus, we would first figure out how much maximum deadline we can get and fill an array of days[maxDead + 1] with -1.
4. We try iterating from the deadLine (jobs[i].dead) and try to check which is the first vacant spot we can do that particular task (days[i] == -1). If we get one, we include that job on that particular day and increment our maxProfit as maxProfit += jobs[i].profit
5. Otherwise if our index pointer becomes equal to 0, it means we cannot finish the current job before its deadLine, so we ignore it.
*/

#include <bits/stdc++.h> 

static bool cmp(vector<int> &A , vector<int> &B)
{
    return A[1] > B[1] ;
}

int jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size() ;

    sort(jobs.begin() , jobs.end() , cmp) ; // We sort the given vector based on descending order of Profits

    int maxDead = 0 ;  int maxProfit = 0 ;

    for(int i = 0 ; i < n ; i++)  maxDead = max(maxDead , jobs[i][0]) ;

    vector<int> days(maxDead + 1 , -1) ; // We create an array days[] of size (maxDead + 1) to keep track of which job we are doing on what day

    for(int i = 0 ; i < n ; i++)
    {
        int deadLine = jobs[i][0] ;
       
        while(deadLine > 0 && days[deadLine] != -1)  deadLine-- ;

        if(deadLine == 0)  continue ; // We have found no days remaining to do the current job before its deadline

        days[deadLine] = i + 1 ; // We include the Current Job and mark it in our days[] array
        maxProfit += jobs[i][1] ; // And we also include its profit
    }

    return maxProfit ;
}


// Time Complexity:  O(N * Log N) + O(N * MaxDeadLine)
// Space Complexity: O(MaxDeadLine)
