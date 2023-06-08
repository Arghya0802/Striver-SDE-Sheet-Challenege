/* Approach: Remains same but I have modified my mergeSort technique and made the code for industry level from Striver sir's Video */

#include <bits/stdc++.h> 
using ll = long long int ;

void merge(int low , int mid , int high , ll arr[])
{
    int left = low ; int right = mid + 1 ;    
    
    vector<int> temp ;
    
    while(left <= mid && right <= high)
    {
        if(arr[left] < arr[right])
        {
            temp.push_back(arr[left]) ; left++ ;
        }

        else
        {
            temp.push_back(arr[right]) ; right++ ;
        }
    }

    for(; left <= mid ; left++)    temp.push_back(arr[left]) ;
    
    for(; right <= high ; right++) temp.push_back(arr[right]) ;
    
    for(int i = low ; i <= high ; i++)  arr[i] = temp[i - low] ;

    return ;
}

ll countInversions(int low , int mid , int high , ll arr[])
{
    ll ans = 0 ;
    
    int left = low ; int right = mid + 1 ;

    while(left <= mid && right <= high)
    {
        if(arr[left] > arr[right])
        {
            ans += (mid + 1 - left) ;  right++ ;
        }

        else left++ ;
    }    

    return ans ;
}

ll mergeSort(int low , int high , ll arr[])
{
    if(low >= high)  return 0 ;

    ll cnt = 0 ; int mid = low + (high - low) / 2 ;

    cnt += mergeSort(low , mid , arr) ;
    cnt += mergeSort(mid + 1 , high , arr) ;

    cnt += countInversions(low , mid , high , arr) ;
    
    merge(low , mid , high , arr) ;

    return cnt ;    
}

long long getInversions(long long arr[] , int n)
{
    return mergeSort(0 , n - 1 , arr) ; 
}

// Time Complexity:  O(N * Log N)
// Space Complexity: O(N)
