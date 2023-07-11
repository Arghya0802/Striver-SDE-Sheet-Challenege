// LeetCode Link:  https://leetcode.com/problems/rotting-oranges/
// --------------------------------------------------------------

#include <bits/stdc++.h>
using pp = pair<int, pair<int , int>> ;

bool isOkay(int nRow , int nCol , int m , int n , vector<vector<int>> &vis , vector<vector<int>> &grid)
{
    if(nRow < 0 || nRow >= m || nCol < 0 || nCol >= n)  return false ;

    if(vis[nRow][nCol] == 1 || grid[nRow][nCol] == 0)  return false ;

    return true ;
}

int minTimeToRot(vector<vector<int>>& grid, int m , int n)
{
    vector<vector<int>> visited(m , vector<int> (n , 0) ) ;

    queue<pp> q ;  int totalFresh = 0 ;

    for(int row = 0 ; row < m ; row++)
    {
        for(int col = 0 ; col < n ; col++)
        {
            if(grid[row][col] == 1)  totalFresh += 1 ;

            if(grid[row][col] == 2)
            {
                visited[row][col] = 1 ;

                q.push(make_pair(0 , make_pair(row , col) ) ) ;
            }
        }
    }

    int x[] = {-1 , +1 , 0 , 0} ;  int y[] = {0 , 0 , -1 , +1} ;

    int maxSteps = 0 ;

    while(!q.empty() )
    {
        int steps = q.front().first ; int row = q.front().second.first ;
        int col = q.front().second.second ; q.pop() ;

        maxSteps = max(maxSteps , steps) ;

        for(int i = 0 ; i < 4 ; i++)
        {
            int nRow = row + x[i] ;  int nCol = col + y[i] ;

            if(isOkay(nRow , nCol , m , n , visited , grid) )
            {
                totalFresh-- ;

                q.push(make_pair(steps + 1 , make_pair(nRow , nCol) ) ) ;

                visited[nRow][nCol] = 1 ;
            }
        }
    }

    return totalFresh == 0 ? maxSteps : -1 ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
