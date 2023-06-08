// LeetCode Link: https://leetcode.com/problems/two-sum/
// --------------------------------------------------------

/* The LeetCode one is a simple problem using Hashing.
The CodeStudio one is a little more complex but can be solved using Hashing only

Approach:
1. For every number A, check if (target - A) is present inside your hashMap or not. If so, push the pair for the cnt of map[target - A], as we need to find all such pairs.
2. This works because, for element A, we can form a pair with any of the elements with (target - A). That's why we need to run a loop to put all the valid pairs inside our 2D ans[][] vector.
3. Before returning, we need to sort our ans[][] vector as well.
*/

#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int target)
{
   int n = arr.size() ;
   
   vector<vector<int>> ans ;  unordered_map<int , int> map ;

   for(int i = 0 ; i < n ; i++)
   {
      int A = arr[i] ; int B = target - A ;

      if(map.find(B) != map.end() )
      {
         int freq = map[B] ;

         while(freq--)
         {
            if(A < B)  ans.push_back( {A , B} ) ;

            else ans.push_back( {B , A} ) ;
         }
      }

      map[A] += 1 ;
   }

   sort(ans.begin() , ans.end() ) ;

   return ans ;
}

// Time Complexity:  O(N * Log N) [ For sorting our ans[][] vector ]
// Space Complexity: O(N)
