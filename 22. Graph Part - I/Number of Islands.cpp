// LeetCode link:  https://leetcode.com/problems/number-of-islands/description/
// ---------------------------------------------------------------------------

class Solution {
private:
    
void dfs(int currentRow , int currentCol , int m , int n , vector<vector<char>> &grid)
{
    if(currentRow < 0 || currentRow >= m || currentCol < 0 || currentCol >= n)
        return ;
    
    if(grid[currentRow][currentCol] == '0')
        return ;
    
    if(grid[currentRow][currentCol] == '2')
        return ;
    
    grid[currentRow][currentCol] = '2' ;
    
    vector<vector<int>> directions = { {-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1} } ;
    
    for(vector<int> &dir : directions)
    {
        int x = dir[0] ;
        int y = dir[1] ;
        
        dfs(currentRow + x , currentCol + y , m , n , grid) ;
    }
    
    return ;
}
    
public:
    int numIslands(vector<vector<char>>& grid) {
        
    int m = grid.size() ;
    int n = grid[0].size() ;
        
    int islands = 0 ;
        
    for(int row = 0 ; row < m ; row++)
    {
        for(int col = 0 ; col < n ; col++)
        {
            if(grid[row][col] == '1')
            {
                dfs(row , col , m , n ,grid) ;
                islands++ ;
            }
        }
    }
        
    return islands ;
        
}
};

// Time Complexity:  O(M * N)
// Space Complexity: O(M * N) [Recursive Stack Space]
