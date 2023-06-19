// LeetCode Link:  https://leetcode.com/problems/n-queens/description/
// --------------------------------------------------------------------

/* Approach
*/

#include<bits/stdc++.h>

void makeChessBoard(vector<vector<int>> &board , int n , vector<vector<int>> &ans)
{
    vector<int> temp ;

    for(int row = 0 ; row < n ; row++)
    {
        for(int col = 0 ; col < n ; col++)  temp.push_back(board[row][col]) ;
    }

    ans.push_back(temp) ;
}

bool rowSafe(int row , int n , vector<vector<int>> &board)
{
    for(int col = 0 ; col < n ; col++)
    {
        if(board[row][col] == 1)  return false ;
    }

    return true ;
}

bool colSafe(int col , int n , vector<vector<int>> &board)
{
    for(int row = 0 ; row < n ; row++)
    {
        if(board[row][col] == 1)  return false ;
    }

    return true ;
}

bool diagonalSafe(int row , int col , int n , vector<vector<int>> &board)
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

bool isOkay(int row , int col , int n , vector<vector<int>> &board)
{
    bool c1 = rowSafe(row , n , board) ;

    bool c2 = colSafe(col , n , board) ;  

    bool c3 = diagonalSafe(row , col , n , board) ;

    return c1 && c2 && c3 ;
}

void solve(int row , int n , vector<vector<int>> &board , vector<vector<int>> &ans)
{
    if(row == n)
    {
        makeChessBoard(board , n , ans) ;  return ;
    }

    for(int col = 0 ; col < n ; col++)
    {
        if(isOkay(row , col , n , board) == true)
        {
            board[row][col] = 1 ;

            solve(row + 1 , n , board , ans) ;

            board[row][col] = 0 ;
        }
    }

    return ;
}

vector<vector<int>> solveNQueens(int n) 
{
    vector<vector<int>> board(n , vector<int> (n , 0) ) ;
    vector<vector<int>> ans ;

    solve(0 , n , board , ans) ;

    return ans ;
}

// Time Complexity:  O(Exponential)
// Space Complexity: O(Exponential) [For recursive stack space]
