// GFG Link:  https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// ------------------------------------------------------------------------------

/* Approach
*/

#include <bits/stdc++.h> 

void ratInMaze(int row , int col , int n , vector<int> &path , vector<vector<int>> &maze , vector<vector<int>> &ans)
{
    if(row < 0 || row >= n || col < 0 || col >= n)  return ;

    if(maze[row][col] == 0 || maze[row][col] == 2)  return ;

    if(row == n - 1 && col == n - 1)
    {
        int index = (row * n) + col ;  path[index] = 1 ;

        ans.push_back(path) ;  return ;
    }

    maze[row][col] = 2 ;

    int x[] = {-1 , +1 , 0 , 0} ;  int y[] = {0 , 0 , -1 , +1} ;

    for(int i = 0 ; i < 4 ; i++)
    {
        int nRow = row + x[i] ;  int nCol = col + y[i] ;

        int index = (row * n) + col ;

        path[index] = 1 ;

        ratInMaze(nRow , nCol , n , path , maze , ans) ;

        path[index] = 0 ;
    }

    maze[row][col] = 1 ;
    
    return ;
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n)
{
  vector<vector<int>> ans ;
  vector<int> path(n * n , 0) ;

  ratInMaze(0 , 0 , n , path , maze , ans) ;

  return ans ;
}

// Time Complexity:  O(4 ^ (N * N) or Exponential)
// Space Complexity: O(4 ^ (N * N) or Exponetial) [For the Recursive Stack Space]
