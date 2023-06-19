// LeetCode Link:  https://leetcode.com/problems/n-queens/description/
// --------------------------------------------------------------------

/* Approach [ Recursion & Backtracking]
1. We need to make such a configuration that we could place N Queens inside our ChessBoard without them canceling each other.
2. We need to try all such possible configurations and use the function isPossible() which checks if we can place our Queen at any cell (r,c).
3. If true, we place the Queen and ask for recursion to do the rest of the task.
4. If false, we look for other configurations
5. Whenever we have placed N Queens, we put that configuration inside our ans[] vector and return back {Base Case}
*/

#include<bits/stdc++.h>

void makeChessBoard(vector<vector<int>> &board , int n , vector<vector<int>> &ans) // Makes our ChessBoard and puts it inside our ans[][] vector
{
    vector<int> temp ;

    for(int row = 0 ; row < n ; row++)
    {
        for(int col = 0 ; col < n ; col++)  temp.push_back(board[row][col]) ;
    }

    ans.push_back(temp) ;
}

bool rowSafe(int row , int n , vector<vector<int>> &board) // Checks if the Row is Safe for the Queen to be placed or not
{
    for(int col = 0 ; col < n ; col++)
    {
        if(board[row][col] == 1)  return false ;
    }

    return true ;
}

bool colSafe(int col , int n , vector<vector<int>> &board) // Checks if the Column is Safe for the Queen to be placed or not
{
    for(int row = 0 ; row < n ; row++)
    {
        if(board[row][col] == 1)  return false ;
    }

    return true ;
}

bool diagonalSafe(int row , int col , int n , vector<vector<int>> &board) // Checks if the Diagonals are Safe for the Queen to be placed or not
{
    // As we are moving from Top to Bottom, so we need to check for Upper Part of Left and Right Diagonals only
    
    int r = row ; int c = col ;

    // Upper Left Diagonal  
    while(r >= 0 && c >= 0)
    {
        if(board[r][c] == 1)  return false ;

        r-- ; c-- ;
    }

    r = row ; c = col ;

    // Upper Right Diagonal
    while(r >= 0 && c < n)
    {
        if(board[r][c] == 1)  return false ;

        r-- ;  c++ ;
    }

    return true ;
}

bool isPossible(int row , int col , int n , vector<vector<int>> &board) // Calls rowSafe(), colSafe() and diagonalSafe() and returns accordingly
{
    bool c1 = rowSafe(row , n , board) ;

    bool c2 = colSafe(col , n , board) ;  

    bool c3 = diagonalSafe(row , col , n , board) ;

    return c1 && c2 && c3 ; // Returns true if all the values are true else returns false
}

void solveQueens(int row , int n , vector<vector<int>> &board , vector<vector<int>> &ans)
{
    if(row == n) // Base Case
    {
        makeChessBoard(board , n , ans) ;  return ;
    }

    for(int col = 0 ; col < n ; col++)
    {
        if(isPossible(row , col , n , board) == true) // Checking if it's possible to put a Queen at the current configuration or not
        {
            board[row][col] = 1 ; // Puts Queen at (row, col) position

            solveQueens(row + 1 , n , board , ans) ; // Asks recursion to do rest of the task

            board[row][col] = 0 ; // Backtracks and undo the change
        }
    }

    return ;
}

vector<vector<int>> solveNQueens(int n) 
{
    vector<vector<int>> board(n , vector<int> (n , 0) ) ;
    vector<vector<int>> ans ;

    solveQueens(0 , n , board , ans) ;

    return ans ;
}

// Time Complexity:  O(Exponential)
// Space Complexity: O(Exponential) [For recursive stack space]
