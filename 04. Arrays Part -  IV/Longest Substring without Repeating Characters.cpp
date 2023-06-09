// LeetCode link:  https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// ----------------------------------------------------------------------------------------------------------

/* Approach [Sliding Window Variable Size]:
1. We need 2 pointers start and end and a hashSet to keep track of the unique elements inside our string.
2. Every time, we check if the current character is already present inside our hashSet or not. If yes, we discard/erase all the elements starting from the end till we delete and find that character. We also increment the end by 1 every time to find the new character we want to delete. 
3. This approach works because once we find a duplicate element, all the elements starting from the end till the first occurrence of that character is useless to us because we need unique characters and subarrays to be contiguous. If we club these together, we can conclude all such elements are useless to us and hence can be erased from our hashSet. 
4. To find the length of the current subarray containing unique characters we can use the formula, (start - end + 1) and always update our ans with the maximum of (ans, start - end + 1).
*/

#include <bits/stdc++.h> 

int uniqueSubstrings(string &input)
{
    int n = input.size() ;

    int end = 0 ;  int maxCnt = 0 ;

    unordered_set<char> hashSet ;

    for(int start = 0 ; start < n ; start++)
    {
        char accept = input[start] ; 

        while(end <= start && hashSet.find(accept) != hashSet.end() ) 
        {
            char discard = input[end] ; end++ ;

            hashSet.erase(discard) ;
        }
        
        hashSet.insert(accept) ;
        
        maxCnt = max(maxCnt , start - end + 1) ;
    }

    return maxCnt ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
