 // LeetCode Link:  https://leetcode.com/problems/set-matrix-zeroes/
//--------------------------------------------------------------------
// Approach:
// We store all such (row , col) which has a value equals 0 and update our rowZeroIndex and colZeroIndex accordingly
// This prevents us from mutliple calls to the same Row or Column and saves our time
//---------------------------------------------------------------------
#include <bits/stdc++.h>

// Sets all the elements in the particular row and column as zero depending on the value of isRow
void setMatrixZero(int ind , int len , bool isRow , vector<vector<int>> &matrix)
{
	if(isRow == true)
	{
		for(int col = 0 ; col < len ; col++)  matrix[ind][col] = 0 ;
	}

	else
	{
		for(int row = 0 ; row < len ; row++)  matrix[row][ind] = 0 ;
	}

	return ;
}

void setZeros(vector<vector<int>> &matrix)
{
	int m = matrix.size() ; int n = matrix[0].size() ;
	
  // rowZeroIndex[] and colZeroIndex vectors are used to keep track of the rows and columns which contains a zero respectively
  
	vector<int> rowZeroIndex(m , 0) ; vector<int> colZeroIndex(n , 0) ;

	for(int row = 0 ; row < m ; row++)
	{
		for(int col = 0 ; col < n ; col++)
		{
			if(matrix[row][col] == 0) 
			{
				rowZeroIndex[row] += 1 ; colZeroIndex[col] += 1 ;
			}
		}
	}

	for(int ind = 0 ; ind < m ; ind++)
	{
		if(rowZeroIndex[ind] > 0)  setMatrixZero(ind , n , true , matrix) ;
	}

	for(int ind = 0 ; ind < n ; ind++)
	{
		if(colZeroIndex[ind] > 0)  setMatrixZero(ind , m , false , matrix) ;
	}

	return ;
}

// Time Complexity:  O(M * N) [For traversing the entire matrix]
// Space Complexity: O(M + N) [For using rowZero and colZero vectors]
