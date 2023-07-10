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
void binaryTreeToLinkedList(BinaryTreeNode<int> *root , vector<BinaryTreeNode<int>*> &ans)
{
    if(!root)  return ;

    binaryTreeToLinkedList(root -> left , ans) ;

    ans.push_back(root) ;

    binaryTreeToLinkedList(root -> right , ans) ;

    // root -> right = prev[0] ;  prev[0] = root ;
    
    return ;
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) 
{
    // vector<BinaryTreeNode<int>*> prev ;  prev.push_back(NULL) ; 

    vector<BinaryTreeNode<int>*> ans ;

    binaryTreeToLinkedList(root , ans) ;

    BinaryTreeNode<int>* prev = ans[0] ;  

    int n = ans.size() ;

    for(int i = 1 ; i < n ; i++)
    {
        BinaryTreeNode<int>* node = ans[i] ;

        prev -> right = node ;
        node -> left = prev ;

        prev = node ;
    }

    return  ans[0] ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
