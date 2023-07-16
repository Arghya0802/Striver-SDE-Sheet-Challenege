// LeetCode link:  https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
// ------------------------------------------------------------------------------

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
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
#include<bits/stdc++.h>
struct NodeValue 
{
    int maxSize , minVal , maxVal ;

    NodeValue(int x , int y , int z)
    {
        maxSize = x ;  minVal = y ; maxVal = z ;
    }
};

NodeValue *findLargestBST(TreeNode<int>* root)
{
    if(!root)  return new NodeValue(0 , INT_MAX , INT_MIN) ;

    if(!root -> left && !root -> right)  return new NodeValue(1 , root -> data , root -> data) ;

    auto leftNode  = findLargestBST(root -> left) ;
    auto rightNode = findLargestBST(root -> right) ;

    if(leftNode -> maxVal < root -> data && root -> data < rightNode -> minVal)
    {
        int size = 1 + leftNode -> maxSize + rightNode -> maxSize ;
        int leftVal  = min(leftNode -> minVal , root -> data) ;
        int rightVal = max(rightNode -> maxVal , root -> data) ;

        auto newBST = new NodeValue(size , leftVal , rightVal) ;

        return newBST ;
    }

    else  return new NodeValue(max(leftNode -> maxSize , rightNode -> maxSize) , INT_MIN , INT_MAX) ;
}

int largestBST(TreeNode<int>* root) 
{
    return findLargestBST(root) -> maxSize ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
