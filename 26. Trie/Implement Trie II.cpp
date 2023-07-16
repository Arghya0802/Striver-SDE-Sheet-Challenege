
#include <bits/stdc++.h> 
// using pp = pair<Node * , int> ;

struct Node 
{
    Node *links[26] ;  
    
    int countPrefix = 0 ; int endWith = 0 ;
    
    bool flag = false ;

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

    void increaseEnd()
    {
        endWith++ ;
    }

    void increasePrefix() 
    {
        countPrefix++ ;
    }

    void eraseEnd() 
    {
        endWith-- ;
    }

    void decreasePrefix()
    {
        countPrefix-- ;
    }

    int getEnd() 
    {
        return endWith ;
    }

    int getPrefix() 
    {
        return countPrefix ;
    }
};

class Trie{

    private:
    Node *root ;

    public:

    Trie()
    {
        root = new Node ;
    }

    void insert(string &word)
    {
        Node *node = root ;

        for(char ch : word)
        {
            if(!node -> containsKey(ch) )
            {
                Node *newNode = new Node ;

                node -> put(ch , newNode) ;
            }

            node = node -> get(ch) ;  node -> increasePrefix() ;
        }

        node -> setEnd() ;  node ->increaseEnd() ;
    }

    int countWordsEqualTo(string &word)
    {
        Node *node = root ; 

        for(char ch : word)
        {
            if(!node -> containsKey(ch) )  return 0 ;

            node = node -> get(ch) ;
        }

        return node -> getEnd() ;
    }

    int countWordsStartingWith(string &word)
    {
        Node *node = root ;  

        for(char ch : word)
        {
            if(!node -> containsKey(ch) )  return 0 ;

            node = node -> get(ch) ;
        }

        return node -> getPrefix() ;
    }

    void erase(string &word)
    {
        Node *node = root ;

        for(char ch : word)
        {
            
            if(!node -> containsKey(ch) )  return ;

            node = node -> get(ch) ;  

            node -> decreasePrefix() ;            
        }

        node -> eraseEnd() ;  return ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
