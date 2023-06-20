// LeetCode Link:  https://leetcode.com/problems/sudoku-solver/description/
// -----------------------------------------------------------------------

/* Approach [Recursion + Backtracking]
1. Exactly the same as N-Queens' problem. Instead of placing Queens, we need to place numbers from 1 to 9 and check if they satisfy the condition of Sudoku or not
2. We need to ensure that a particular value doesn't repeat in its row, column, and Sub-Grid. 
3. To ensure this, we have rowSafe(), columnSafe() and, subGridSafe() functions 
4. Whenever we get a true from our recursive function, we immediately return because we have found the one and only possible solution for the Sudoku.
5. To get the startRow and startCol of any (row, col), we use the formula:
                                       startRow = (row / 3) * 3 ;      startCol = (col / 3) * 3
*/


// Checks if we can place the given value in the Particular Row
bool rowSafe(int row , int val , int matrix[9][9])
{
    for(int col = 0 ; col < 9 ; col++)
    {
        if(matrix[row][col] == val)  return false ;
    }

    return true ;
}

// Checks if we can place the given value in the Particular Column
bool columnSafe(int col , int val , int matrix[9][9])
{
    for(int row = 0 ; row < 9 ; row++)
    {
        if(matrix[row][col] == val)  return false ;
    }

    return true ;
}

// Checks, if we are having any repetition of the number val inside its 3*3 Grid
bool subGridSafe(int row , int col , int val , int matrix[9][9])
{
    int startRow = (row / 3) * 3 ;
    int startCol = (col / 3) * 3 ;

    for(int r = startRow ; r <= (startRow + 2) ; r++)
    {
        for(int c = startCol ; c <= (startCol + 2) ; c++) 
        {
            if(matrix[r][c] == val)  return false ;
        }
    }

    return true ;
}

bool isPossible(int row , int col , int val , int matrix[9][9])
{
    bool c1 = rowSafe(row , val , matrix) ;

    bool c2 = columnSafe(col , val , matrix) ;

    bool c3 = subGridSafe(row , col , val , matrix) ;

    return c1 && c2 && c3 ;
}

bool solveSudoku(int row , int col , int matrix[9][9])
{
    if(row == 9)  return true ; // Base Case

    if(col == 9)  return solveSudoku(row + 1 , 0 , matrix) ; // If one column is filled, we move to the next row

    if(matrix[row][col] != 0)  return solveSudoku(row , col + 1 , matrix) ; // if the cell is already filled, we move to its adjacent cell

    // Otherwise we try all possible combinations for the given empty cell
    for(int val = 1 ; val <= 9 ; val++)
    {
        if(isPossible(row , col , val , matrix) ) // If its safe to place that number in that position
        {
            matrix[row][col] = val ; // We do so

            // And asks recursion to do the rest of the task
            if( solveSudoku(row , col + 1 , matrix) )  return true ;

            matrix[row][col] = 0 ; // Otherwise, we backtrack and undo the change
        }
    }

    return false ;
}

bool isItSudoku(int matrix[9][9]) 
{
    return solveSudoku(0 , 0 , matrix) ;
}


// Time Complexity:  O(Exponential)
// Space Complexity: O(Exponential)
