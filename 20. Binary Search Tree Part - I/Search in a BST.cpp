// LeetCode Link: https://leetcode.com/problems/search-in-a-binary-search-tree/ 
// ----------------------------------------------------------------------------

#include <bits/stdc++.h> 
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) 
{
    while(root)
    {
        if(root -> data == x)  return true ;

        else if(root -> data < x)  root = root -> right ;

        else root = root -> left ;
    }    

    return false ;
}

// Time Complexity:  O(Log N)
// Space Complexity: O(1)
