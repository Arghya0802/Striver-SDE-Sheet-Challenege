// LeetCode link: https://leetcode.com/problems/search-a-2d-matrix/
// ---------------------------------------------------------------------

/* Approach [ Stair-Case Algorithm ]:
1. We start at the top right-hand side corner (0, n - 1) and we make our move accordingly.
2. We check if mat[row][col]) == target , if true we directly return true
3. Else if we check if mat[row][col] < target, then we increment our r by 1.
4. Else we decrement our c by 1.
5. At the end, if we came out of our while loop, we return false.
6. The intuition comes from the fact that our rows are sorted in ascending order and the last element of a previous row is always less than the first element of our previous row.
7. Thus we can check if our current value is less than, greater than, or equal to our target. If it is equal, we return true directly. If it's less we need to move down to the next row because the value we are currently at is the maximum possible in the row, or else we need to move to the left if our value > target.
*/

bool searchMatrix(vector<vector<int>>& mat, int target) 
{
    int m = mat.size() ;  int n = mat[0].size() ;

    int startRow = 0 ; int startCol = n - 1 ;

    while(startRow < m && startCol >= 0)
    {
        int val = mat[startRow][startCol] ;

        if(val == target)  return true ;

        else if(val < target)  startRow++ ;

        else startCol-- ;
    }

    return false ;
}

// Time Complexity:  O(M + N)
// Space Complexity: O(1)
