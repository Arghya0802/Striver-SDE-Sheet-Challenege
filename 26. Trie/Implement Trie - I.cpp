// LeetCode Link:  https://leetcode.com/problems/implement-trie-prefix-tree/
// -------------------------------------------------------------------------

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */


struct Node 
{
    Node *links[26] ; 

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
};

class Trie {

Node *root ;
public:

    /** Initialize your data structure here. */
    Trie() 
    {
        root = new Node ;
    }

    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        Node *node = root ;

        for(char ch : word)
        {
            if(!node -> containsKey(ch) ) 
            {
                Node *newNode = new Node ;

                node -> put(ch , newNode) ;
            }

            node = node -> get(ch) ;
        }

        node ->setEnd() ;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        Node *node = root ;

        for(char ch : word)
        {
            if(!node -> containsKey(ch) )  return false ;

            node = node -> get(ch) ;
        }

        return node -> isEnd() ;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        Node *node = root ;

        for(char ch : prefix)
        {
            if(!node -> containsKey(ch) )  return false ;

            node = node -> get(ch) ;
        }

        return true ;
    }
};

