// Link:  https://leetcode.com/problems/binary-tree-preorder-traversal/
// --------------------------------------------------------------------

#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void preOrder(TreeNode *root , vector<int> &ans) 
{
    if(!root)  return ;

    ans.push_back(root -> data) ;

    preOrder(root -> left , ans) ;

    preOrder(root -> right , ans) ;

    return ;
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans ;

    preOrder(root , ans) ;

    return ans ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
