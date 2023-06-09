// GFG Link: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
// -----------------------------------------------------------------------------------------

/* Approach [Longest Subarray with K-sum or Zero-Sum]:
1. Whether we need to find the longest subarray with a sum equals K or Zero(0), our approach remains the same.
2.  We need to use prefixSum + hashing to calculate the length of such subarray with a given sum.
3. To handle an edge case, we need to initialize our map[0] = -1. This ensures that if the entire subarray has a sum equal to K, we don't miss out on counting its length.
4. We use prefixSum to calculate the sum till the i-th index. And every time we would check if (prefixSum - K) is present inside our hashMap or not. If true, we calculate the length as(i - map[prefixSum - K]) and store the maximum of (ans, len) inside our ans variable. 
5. This approach works because if we have visited a subarray sum and the next time we visit it, it surely means that the middle element in between had a sum equals K. So that's the approach behind this. 
6. Lastly, make sure we store the first occurrence of the index of any prefixSum as we are trying to calculate the maximum possible length.
*/

#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector <int> &arr) 
{
  int n = arr.size() ;

  int ans = 0 ;  int prefixSum = 0 ;

  unordered_map<int , int> hashMap ;  hashMap[0] = -1 ;

  for(int i = 0 ; i < n ; i++)
  {
      prefixSum += arr[i] ;

      if(hashMap.find(prefixSum) != hashMap.end() )  
      {
          int len = i - hashMap[prefixSum] ;

          ans = max(ans , len) ;
      }

      else  hashMap[prefixSum] = i ;
  }


  return ans ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
