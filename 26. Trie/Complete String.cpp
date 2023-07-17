#include <bits/stdc++.h> 

struct Node
{
    Node *links[26] ;  bool flag = false ;
    
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL ;
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

struct Trie 
{
    Node *root ;

    Trie()
    {
        root = new Node() ;
    }

    void insertWord(string s)
    {
        Node *node = root ;

        for(char ch : s)
        {
            if(!node -> containsKey(ch) )  node -> put(ch , new Node() ) ;

            node = node -> get(ch) ;
        }

        node -> setEnd() ;
    }

    bool searchWord(string s)
    {
        Node *node = root ;

        for(char ch : s)
        {
            node = node -> get(ch) ;

            if(!node -> isEnd() )  return false ;
        }

        return true ;
    }
};

string completeString(int n, vector<string> &a)
{
    Trie *root = new Trie() ;

    for(auto s : a)  root -> insertWord(s) ;

    string ans = "" ;

    for(auto s : a)
    {
        if(root -> searchWord(s) )
        {
            if(ans.size() < s.size() )  ans = s ;

            else if(ans.size() == s.size() && (s < ans) )  ans = s ;
        }
    }

    if(ans.size() == 0)  return "None" ;

    return ans ;
}

// Time Complexity:  O(N * K)  [ K is the Average length of each word ]
// Space Complexity: O(N)
