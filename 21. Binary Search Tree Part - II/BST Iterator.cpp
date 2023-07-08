// LeetCode Link:  https://leetcode.com/problems/binary-search-tree-iterator/description/
// -------------------------------------------------------------------------------------

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

class BSTiterator
{
    private:
    vector<int> arr ; 
    int i ;

    void inOrder(TreeNode<int> *root)
    {
        if(!root)  return ;

        inOrder(root -> left) ;

        arr.push_back(root -> data) ;

        inOrder(root -> right) ;
    }

    public:
    BSTiterator(TreeNode<int> *root)
    {
        inOrder(root) ;  i = 0 ;
    }

    int next()
    {
        if(!hasNext() )  return -1 ;

        int x = arr[i] ;  i++ ;

        return x ;
    }

    bool hasNext()
    {
        return i < arr.size() ;
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/

// Time Complexity:  O(N)
// Space Complexity: O(N)
