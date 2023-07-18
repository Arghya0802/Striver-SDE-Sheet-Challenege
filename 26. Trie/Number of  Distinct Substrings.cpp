#include <bits/stdc++.h> 
#include <bits/stdc++.h> 

struct Node
{
    Node *links[26] ;  bool flag = false ;

    bool containsKey(char ch)
    {
        return links[ch - 'a'] ;
    }

    void put(char ch , Node *node)
    {
        links[ch - 'a'] = node ;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'] ;
    }

    void setEnd()
    {
        flag = true ;
    }

    bool isEnd()
    {
        return flag ;
    }
};



int distinctSubstring(string &word) 
{
    int n = word.size() ;  int disCnt = 0 ;

    Node *root = new Node() ;

    for(int i = 0 ; i < n ; i++)
    {
        Node *node = root ;
        
        for(int j = i ; j < n ; j++)
        {
            char ch = word[j] ;

            if(!node -> containsKey(ch) )
            {
                disCnt++ ;  node -> put(ch , new Node() ) ;
            }

            node = node -> get(ch) ; 
        }
    }
    
    return disCnt ;
}


// Time Complexity:  O(N * 2)
// Space Complexity: O(N ^ 2) [If all the substrings are distinct, we would be storing all of them into our Trie Data Structure]
