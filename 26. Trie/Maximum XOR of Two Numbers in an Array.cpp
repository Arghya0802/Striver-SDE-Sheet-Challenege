// LeetCode Link:  https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// -------------------------------------------------------------------------------------

#include <bits/stdc++.h> 
struct Node
{
    Node *links[2] ;

    bool containsKey(int bit)
    {
        return links[bit] != NULL ;
    }

    void put(int bit , Node *node)
    {
        links[bit] = node ;
    }

    Node *get(int bit)
    {
        return links[bit] ;
    }
};

class Trie
{
    private:
    Node *root ;

    public:

    Trie()
    {
        root = new Node() ;
    }
    
    void insert(int num)
    {
        Node *node = root ;

        for(int i = 31 ; i >= 0 ; i--)
        {
            int bit = (num >> i) & 1 ;

            if(!node -> containsKey(bit) )  node -> put(bit , new Node() ) ;

            node = node -> get(bit) ;
        }
    }

    int maxXOR(int num)
    {
        Node *node = root ;  int maxNum = 0 ;

        for(int i = 31 ; i >= 0 ; i--)
        {
            int bit = (num >> i) & 1 ;

            if( node -> containsKey(1 - bit) )
            {
                maxNum = maxNum | (1 << i) ;  node = node -> get(1 - bit) ;
            }

            else  node = node -> get(bit) ;
        }

        return maxNum ;
    }
};

int maximumXor(vector<int> &A)
{
    Trie *trie = new Trie() ;

    int maxXOR = 0 ;

    for(int nums : A)  trie -> insert(nums) ;

    for(int nums : A)
    {
        int maxi = trie -> maxXOR(nums) ;

        maxXOR = max(maxXOR , maxi) ;
    }

    return maxXOR ;
}

// Time Complexity:  O(N * 32)
// Space Complexity: O(N * 32)
