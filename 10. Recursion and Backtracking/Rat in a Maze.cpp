// GFG Link:  https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// ------------------------------------------------------------------------------

/* Approach [ Recursion & Backtracking]
1. Our mice start from (0, 0) and it has to reach (N - 1, N - 1) and we need to print all such possible paths.
2. We would use recursion and travel in all 4-directions: Check if we could reach our Target Cell or not, if true, include it inside our answer
3. Else explore all other paths and backtrack and undo the change after we have done so.
4. Make sure we make the current cell as visited otherwise we would be struck in an infinite loop.
*/

#include <bits/stdc++.h> 

void ratInMaze(int row , int col , int n , vector<int> &path , vector<vector<int>> &maze , vector<vector<int>> &ans)
{
    if(row < 0 || row >= n || col < 0 || col >= n)  return ; // If we are moving out of our maze[][] matrix, we return

    if(maze[row][col] == 0 || maze[row][col] == 2)  return ; // If our Current Cell is blocked or already Visited, we return 

    if(row == n - 1 && col == n - 1) // If we have reached our Target Cell
    {
        int index = (row * n) + col ;  path[index] = 1 ; // We update our Path vector

        ans.push_back(path) ;  return ; // We put it inside our ans[][] vector and return
    }

    maze[row][col] = 2 ; // Mark the Cell as Visited

    int x[] = {-1 , +1 , 0 , 0} ;  int y[] = {0 , 0 , -1 , +1} ; // Denotes the Directions where we can move

    for(int i = 0 ; i < 4 ; i++)
    {
        int nRow = row + x[i] ;  int nCol = col + y[i] ;

        int index = (row * n) + col ;

        path[index] = 1 ; // Update our Path vector[]

        ratInMaze(nRow , nCol , n , path , maze , ans) ; // Ask recursion to do rest of the task

        path[index] = 0 ; // Backtrack and undo the change
    }

    maze[row][col] = 1 ; // Backtrack and undo the change
    
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
