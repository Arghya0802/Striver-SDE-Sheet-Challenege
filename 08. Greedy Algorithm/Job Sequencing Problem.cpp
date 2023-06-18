// GFG Link:  https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
// -------------------------------------------------------------------------------------------

/* Approach [Greedy + Sorting]
1. To get the maximum profit, we need to sort the Jobs[] array based on descending order of Profits.
2. Now, to maximize our profit, we would solve a given task as close to its deadline as possible (ideally we would like to solve it on D-Day only)
3. Thus, we would first figure out how much maximum deadline we can get and fill an array of days[maxDead + 1] with -1.
4. We try iterating from the deadLine (jobs[i].dead) and try to check which is the first vacant spot we can do that particular task (days[i] == -1). If we get one, we include that job on that particular day and increment our maxProfit as maxProfit += jobs[i].profit
5. Otherwise if our index pointer becomes equal to 0, it means we cannot finish the current job before its deadLine, so we ignore it.
*/

// Time Complexity:  O(N * Log N) + O(N * MaxDeadLine)
// Space Complexity: O(MaxDeadLine)
