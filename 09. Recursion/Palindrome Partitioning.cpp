// LeetCode Link:  https://leetcode.com/problems/palindrome-partitioning/description/
// ----------------------------------------------------------------------------------

/* Approach [Recursion]
1. As we need to generate all possible palindromic partitions, we need to use Recursion & Backtracking.
2. We start from i = index till i < s.size() and calculate all the prefixes possible inside the For loop.
3. After that, we check whether the current prefix is Palindromic or not.
4. If true, we include the prefix inside our container[] vector and ask recursion to do the rest of the task.
5. After the recursion call has returned, we have to backtrack and undo the change- remove the prefix string from our container[] so that don't include it in other possible partitioning sequences.
*/

#include <bits/stdc++.h>

bool isPalindrome(string &wd)
{
    int low = 0 ;  int high = wd.size() - 1 ;

    while(low <= high)
    {
        if(wd[low] != wd[high])  return false ;

        low++ ; high-- ; 
    }

    return true ;
}

void palindromePartition(int ind , int n , vector<string> &container , string &s , vector<vector<string>> &ans)
{
    if(ind >= n) // Base Case
    {
        ans.push_back(container) ;  return ;
    }

    string prefixStr = "" ; 

    for(int i = ind ; i < n ; i++)
    {
        prefixStr += s[i] ;

        if(isPalindrome(prefixStr) )
        {
            container.push_back(prefixStr) ;

            palindromePartition(i + 1 , n , container , s , ans) ;

            container.pop_back() ;
        }
    }

    return ;
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> ans ; // Stores all the Palindrome Partitions
    vector<string> container ; // Stores the current sequence of Palindrome Partitions

    palindromePartition(0 , s.size() , container , s , ans) ;

    return ans ;
}

// Time Complexity:  O(2 ^ N * N / 2) [2 ^ N is to generate all the substrings, N / 2 is to check if they are Palindrome or not]
// Space Complexity: O(N) [Recursive Stack Space & Ignoring space taken ans[][] and Container vectors respectuvely] 
