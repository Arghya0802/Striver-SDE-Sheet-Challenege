// LeetCode Link:  https://leetcode.com/problems/binary-tree-inorder-traversal/
// ---------------------------------------------------------------------------

/* Simple Recursive Traversal
1. Traverse the  Left Sub Tree
2. Traverse  the Node itself
3. Traverse the Right Sub Tree
*/

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

void inOrderTraversal(TreeNode *root , vector<int> &nums)
{
    if(!root)  return ;

    inOrderTraversal(root -> left , nums) ;

    nums.push_back(root -> data) ;

    inOrderTraversal(root -> right , nums) ;

    return ;
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> inOrder ;

    inOrderTraversal(root , inOrder) ; 

    return inOrder ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
