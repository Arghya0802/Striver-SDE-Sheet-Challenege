// Interview Bit Link:  https://www.interviewbit.com/problems/matrix-median/
// --------------------------------------------------------------------

/* Approach [Binary Search]
1. Our search space will be between [1 ...... 1e9] 
2. We calculate Mid using low + (high - low) / 2
3. For every Mid, we calculate how many numbers are <= mid using binarySearch and adding (ind + 1) to cnt where ind is the index of the last element which is <= Mid
4. If cnt <= (M * N) / 2, it means we need to move to the right side, so we update low = mid + 1
5. Else we need to move to the left part of the search space, so we update high = mid - 1
6. At the end, our answer will be contained in the Low pointer. 
*/

#include<bits/stdc++.h>
using ll = long long int ;

int binarySearch(vector<int> &nums , int n , int target)
{
    int low = 0 ; int high = n - 1 ;  int ans = -1 ;

    while(low <= high)
    {
        int mid = low + (high - low) / 2 ;

        if(nums[mid] <= target)  
        {
            ans = mid ;  low = mid + 1 ;
        }

        else  high = mid - 1 ;
    }

    return ans ;
}

int getMedian(vector<vector<int>> &matrix)
{
    int m = matrix.size() ;  int n = matrix[0].size() ;

    if(m == 1 && n == 1)  return matrix[0][0] ;
    
    ll median = (m * n) / 2 ;
    
    int low = 1 ; int high = 1e5 ; // Declaring our Search Space [1....1e5]

    while(low <= high)
    {
        int mid = low + (high - low) / 2 ;

        int cnt = 0 ;

        for(int row = 0 ; row < m ; row++) 
        {
            int ind = binarySearch(matrix[row] , n , mid) ; // For every row, we calculate how many elements are <= mid using binarySearch

            cnt += (ind + 1) ;   
        }

        if(cnt <= median)  low = mid + 1 ;

        else high = mid - 1 ;
    }

    return low ;
}

// Time Complexity:  O(M * Log N)
// Space Complexity: O(1)
