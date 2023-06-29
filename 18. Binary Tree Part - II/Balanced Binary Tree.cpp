// LeetCode Link:  https://leetcode.com/problems/balanced-binary-tree/description/
// -------------------------------------------------------------------------------

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

int maxDepth(BinaryTreeNode<int> *root)
{
    if(!root)  return 0 ;

    int lh = maxDepth(root -> left) ;
    int rh = maxDepth(root -> right) ;

    return 1 + max(lh , rh) ;
}

bool isBalancedBT(BinaryTreeNode<int>* root) 
{
    if(!root)  return true ;

    int lh = maxDepth(root -> left)  ;
    int rh = maxDepth(root -> right) ;

    if(abs(lh - rh) > 1)  return false ;

    bool leftAns = isBalancedBT(root -> left) ;

    bool rightAns = isBalancedBT(root -> right) ;

    return leftAns && rightAns ;    
}

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N) [Recursive Stack Space]
