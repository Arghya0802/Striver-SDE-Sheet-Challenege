// LeetCode Link:  https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// --------------------------------------------------------------------------------------

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

TreeNode<int> *findLCA(TreeNode<int> *root , int x , int y)
{
    if(!root)  return NULL ;

    if(root -> data == x || root -> data == y)  return root ;
    
    TreeNode<int> *leftAns  = findLCA(root -> left , x , y) ;
    TreeNode<int> *rightAns = findLCA(root -> right , x , y) ;

    if(leftAns && rightAns)  return root ;

    else if(leftAns)  return leftAns ;

    else return rightAns ; 
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    return findLCA(root , x , y) -> data ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N) [Recursive Stack Space is used only]
