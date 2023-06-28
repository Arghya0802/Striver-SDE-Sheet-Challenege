// GFG Link:  https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
// ---------------------------------------------------------------------------------------------

#include <bits/stdc++.h>

int ninjaAndLadoos(vector<int> &A , vector<int> &B , int n1 , int n2 , int k) 
{
    if(n2 < n1)  return ninjaAndLadoos(B, A, n2, n1, k)  ;
        
    int low  = max(0 , k - n2) ;
    int high = min(n1 , k) ;
    
    while(low <= high)
    {
        int cut1 = low + (high - low) / 2 ;
        int cut2 = k - cut1 ;
        
        int l1 = cut1 == 0 ? INT_MIN : A[cut1 - 1] ;
        int l2 = cut2 == 0 ? INT_MIN : B[cut2 - 1] ;
        
        int r1 = cut1 == n1 ? INT_MAX : A[cut1] ;
        int r2 = cut2 == n2 ? INT_MAX : B[cut2] ;
        
        if(l1 <= r2 && l2 <= r1)  return max(l1 , l2) ;
        
        else if(l1 > r2)  high = cut1 - 1 ;
        
        else  low = cut1 + 1 ;
    }
    
    return 1 ;
}

// Time Complexity:  O(Log (min(n1 , n2)) 
// Space Complexity: O(1)
