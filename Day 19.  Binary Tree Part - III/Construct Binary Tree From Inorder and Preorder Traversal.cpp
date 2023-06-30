// LeetCode Link:  https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// --------------------------------------------------------------------------------------------------------

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
TreeNode<int> *buildTree(int low , int high , int &ind , unordered_map<int , int> &map , vector<int> &preOrder)
{
    if(ind >= (int) preOrder.size() )  return NULL ;

    if(low > high)  return NULL ;

    if(low == high)
    {
        TreeNode<int> *newNode = new TreeNode<int> (preOrder[ind]) ;  ind++ ;

        return newNode ;
    }

    int val = preOrder[ind] ; ind++ ;
    TreeNode<int> *root = new TreeNode<int>(val) ;
    int mid = map[val] ;

    root -> left = buildTree(low , mid - 1 , ind , map , preOrder) ;

    root -> right = buildTree(mid + 1 , high , ind , map , preOrder) ;

    return root ;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int n = inorder.size() ;

	unordered_map<int , int> inOrderMap ;

    for(int i = 0 ; i < n ; i++)  inOrderMap[inorder[i]] = i ;
    int ind = 0 ;

    return buildTree(0 , n - 1 , ind , inOrderMap , preorder) ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N) [Recursive + HashMap usage]
