// LeetCode Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
// --------------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int> *constructBST(int &preIndex , int boundary , vector<int> &preOrder)
{
    if(preIndex >= preOrder.size() )  return NULL ;
    if(preOrder[preIndex] > boundary) return NULL ;
    
    int val = preOrder[preIndex] ; preIndex++ ;

    TreeNode<int> *root =  new TreeNode<int> (val) ;

    root -> left  = constructBST( preIndex , val , preOrder) ;

    root -> right = constructBST(preIndex , boundary, preOrder) ;

    return root ;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder)
{
    int ind = 0 ;
    return constructBST(ind , INT_MAX , preOrder) ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N) [Recursive Stack Space]
