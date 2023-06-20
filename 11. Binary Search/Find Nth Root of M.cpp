// Link:
// ------------------------------------------------------

/* Approach:
1. Our answer will always be within the range [1... M ]. Thus we can easily apply BinarySearch for our answer.
2. If pow(mid, N) == M, it means this is our possible answer so we directly return mid.
3. Else if pow(mid, N) < M, we need a bigger value so we move the right side of our search space, that is, we make low = mid + 1
4. Otherwise we make high = mid - 1
5. At the end, if the Nth Root of M doesn't exist, we will be out of our while loop so we return -1.
*/

int NthRoot(int n, int m) 
{
    if(n == 1)  return m ; // If N equals 1, our answer will always be M
    if(m == 1)  return 1 ; // If M equals 1, our answer will always be 1

    // Otherwise, we do BinarySearch from [1... M]

    int low = 1 ; int high = m ;

    while(low <= high)
    {
        int mid = low + (high - low) / 2 ;

        if( pow(mid , n) == m)  return mid ;

        else if( pow(mid , n) < m)  low = mid + 1 ;

        else high = mid - 1 ;
    }

    return -1 ; 
}

// Time Complexity:  O(Log M)
// Space Complexity: O(1)
