// Link:
// ---------------------------------------------------

/* Approach: [Using Merge-Sort Technique]
1.  The idea is very simple. We will perform our normal Merge-Sort process and inside our merge function, we will check if A[i] > B[j]. 
2. If so, we have found our Inversion Pairs so we increment our ans by (m - i)
3. This is the key step in the algorithm. As both of our vectors [A & B] are sorted, so if we find any element in the first vector A[] which is greater than any element of vector B[] then all the corresponding elements of vector B[] will also be valid Inversion Count pairs, that is, they will be smaller than A[i]. 
4. Thus, the no of pairs we can make for the element B[j] is equal to the number of elements we need to process yet in vector A[], which is equal to (m - i)
5. We thus add (m - i) directly into our global ans variable.
6. Please remember, i is used to iterate over vector A[] and j is used to iterate over vector B[].
*/

#include <bits/stdc++.h> 
using ll = long long int ;
ll ans = 0 ;

vector<ll> merge(vector<ll> &A , vector<ll> &B)
{
    vector<ll> merged ;

    int i = 0 , j = 0 ;
    int m = A.size() , n = B.size() ;

    while(i < m && j < n)
    {
        if(A[i] > B[j])
        {
            ans += (m - i) ;

            merged.push_back(B[j]) ; j++ ;
        }

        else
        {
            merged.push_back(A[i]) ; i++ ;
        }
    }

    for(; i < m ; i++)  merged.push_back(A[i]) ;

    for(; j < n ; j++)  merged.push_back(B[j]) ;

    return merged ;
}

vector<ll> mergeSort(int low , int high , vector<ll> &nums)
{
    if(low > high)   return {} ;

    if(low == high)  return {(ll) nums[low]} ;

    int mid = low + (high - low) / 2 ;

    vector<ll> A = mergeSort(low , mid , nums) ;
    vector<ll> B = mergeSort(mid + 1 , high , nums) ;

    return merge(A , B) ;
}

long long getInversions(long long arr[] , int n)
{
    vector<ll> nums ;

    for(int i = 0 ; i < n ; i++)  nums.push_back(arr[i]) ;

    mergeSort(0 , n - 1 , nums) ;
    
    return ans ; 
}

// Time Complexity:  O(N * Log N) [Standard Merge-Sort Time Complexity]
// Space Complexity: O(N) [For using nums[] vector and merge[] vector] and O(Log N) [Height of Recursive function ]
