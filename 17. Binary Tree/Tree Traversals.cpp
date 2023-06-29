#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
void preOrder(BinaryTreeNode<int> *root , vector<int> &nums)
{
    if(!root)  return ;

    nums.push_back(root -> data) ;

    preOrder(root -> left , nums) ;
    
    preOrder(root -> right , nums) ;

    return ;
}

void inOrder(BinaryTreeNode<int> *root , vector<int> &nums)
{
    if(!root)  return ;


    inOrder(root -> left , nums) ;
    
    nums.push_back(root -> data) ;

    inOrder(root -> right , nums) ;

    return ;
}

void postOrder(BinaryTreeNode<int> *root , vector<int> &nums)
{
    if(!root)  return ;


    postOrder(root -> left , nums) ;

    postOrder(root -> right , nums) ;

    nums.push_back(root -> data) ;

    return ;
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>> ans ; 
    vector<int> v1 , v2 , v3 ;

    preOrder(root , v1) ;
    inOrder(root , v2) ;
    postOrder(root , v3) ;

    ans.push_back(v2) ; ans.push_back(v1) ; ans.push_back(v3) ;

    return ans ;
}

// Time Complexity:  O(3 * N)
// Space Complexity: O(N)
