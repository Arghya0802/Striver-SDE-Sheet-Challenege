// LeetCode Link:  https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// --------------------------------------------------------------------------------

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

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
// TreeNode<int> *prev = NULL ;

void flatten(TreeNode<int> *root , TreeNode<int> *prev[])
{
    if(!root)  return ;

    flatten(root -> right , prev) ;
    flatten(root -> left , prev) ;

    root -> right = prev[0] ;
    root -> left = NULL ;

    prev[0] = root ;
    return ;
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *prev[] = {NULL} ;

    flatten(root , prev) ;

    return root ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N) [Recursive Stack Space]
