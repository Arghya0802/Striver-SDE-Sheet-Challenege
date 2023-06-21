// LeetCode Link:  https://leetcode.com/problems/word-break-ii/description/
// ------------------------------------------------------------------------

/* Approach [ Simple recursion and Backtracking]
1. To make our search through the dictionary faster, we use a hashSet
2. We iterate through all the prefixes for i = ind till N and check which prefix is present inside our hashSet.
3. If any prefix is present, we include it inside our vector words[] and ask recursion to do the rest of the task.
4. On returning, we must backtrack and undo the change we made.
5. From our base case, we all possible answers into our ans[] vector by converting them to a string first and adding adequate spaces between every word.
*/

#include <bits/stdc++.h> 

void wordBreak(int ind , int n , vector<string> &words , string &s , unordered_set<string> &dict , vector<string> &ans)
{
    if(ind >= n) // Base Case
    {
        string curr = "" ;

        for(auto it : words)
        {
            curr += it ;  curr += ' ' ;
        }

        curr.pop_back() ; // Eliminate the extra space at the end

        // Adding the string into our ans[] vector and return back
        ans.push_back(curr) ;  return ;
    }

    string prefix = "" ; 

    for(int i = ind ; i < n ; i++)
    {
        prefix += s[i] ;

        if(dict.find(prefix) != dict.end() ) // We include a prefix only if its present inside our hashSet
        {
            words.push_back(prefix) ;

            wordBreak(i + 1 , n , words , s , dict , ans) ; // Ask recursion to do rest of the task

            words.pop_back() ; // Backtrack and undo the change
        }
    }

    return ;
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    unordered_set<string> dict ;

    for(auto it: dictionary)  dict.insert(it) ;

    vector<string> ans ;  vector<string> words ;

    wordBreak(0 , s.size() , words , s , dict , ans) ;

    return ans ;
}

// Time Complexity:  O(Exponential)
// Space Complexity: O(Exponential)
