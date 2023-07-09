// LeetCode Link:  https://leetcode.com/problems/flood-fill/
// ---------------------------------------------------------

#include <bits/stdc++.h>

void dfs(int row , int col , int m , int n , int oldColor, int newColor , vector<vector<int>> &image)
{
    if(row < 0 || row >= m || col < 0 || col >= n)  return ;

    if(image[row][col] != oldColor)  return ;

    image[row][col] = newColor ;

    int x[] = {-1 , +1 , 0 , 0} ;  int y[] = {0 , 0 , -1 , +1} ;

    for(int i = 0 ; i < 4 ; i++)
    {
        int nRow = row + x[i] ;  int nCol = col + y[i] ;

        dfs(nRow , nCol , m , n , oldColor , newColor , image) ;
    }

    return ;
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int m = image.size() ;  int n = image[0].size() ;

    // vector<vector<int>> vis(m ,vector<int> (n , 0) ) ;

    int oldColor = image[x][y] ;

    if(oldColor == newColor)  return image ;

    dfs(x , y , m , n , oldColor , newColor , image) ;

    return image ;
}

// Time Complexity:  O(M * N)
// Space Complexity: O(M * N) [Recursive Stack Space is used only]
