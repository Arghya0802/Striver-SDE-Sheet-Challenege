// LeetCode Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// ---------------------------------------------------------------------------------------------

#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
TreeNode<int> *findLCA(TreeNode<int> *root , int maxP , int minQ)
{
    if(!root)  return NULL ;

    if(root -> data == maxP || root -> data == minQ)  return root ;

    if(root -> data < minQ)  return findLCA(root -> right , maxP , minQ) ;

    else if(root -> data > maxP)  return findLCA(root -> left , maxP , minQ) ;

    TreeNode<int> *leftAns = findLCA(root -> left , maxP , minQ) ;

    TreeNode<int> *rightAns = findLCA(root -> right , maxP , minQ) ;

    if(leftAns && rightAns)  return root ;

    else if(leftAns)  return leftAns ;

    else return rightAns ;
}

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	int maxP = max(P -> data , Q -> data) ;
    int minQ = min(P -> data , Q -> data) ;

    return findLCA(root , maxP , minQ) ;
}

// Time Complexity:  O(Log N)
// Space Complexity: O(Log N) [ Recursive Stack Space ]
