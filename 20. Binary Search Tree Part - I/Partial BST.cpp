// LeetCode Link:  https://leetcode.com/problems/validate-binary-search-tree/description/
// -------------------------------------------------------------------------------------

#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
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

*************************************************************/
bool isBST(BinaryTreeNode<int> *root , long long minVal , long long maxVal)
{
    if(!root)  return true ;

    if(root -> data > maxVal || root -> data < minVal)  return false ;

    bool leftAns  = isBST(root -> left , minVal , root -> data) ;

    bool rightAns = isBST(root -> right , root -> data , maxVal) ;

    return leftAns && rightAns ;
}

bool validateBST(BinaryTreeNode<int> *root) 
{
    return isBST(root , LLONG_MIN , LLONG_MAX) ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
