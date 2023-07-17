#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) 
{
    if(!root)  return ;

    int leftVal  = root -> left  ? root -> left -> data : 0 ;  
    int rightVal = root -> right ? root -> right -> data : 0 ;

    if(leftVal + rightVal < root -> data)  
    {
        if(root -> left)   root -> left -> data = root -> data ;

        if(root -> right)  root -> right -> data = root -> data ;
    }

    else root -> data = leftVal + rightVal ;

    changeTree(root -> left) ;  changeTree(root -> right) ;

    int tot = 0 ;

    if(root -> left)  tot += root -> left -> data ;

    if(root -> right) tot += root -> right -> data ;

    if(root -> left || root -> right)  root -> data = tot ;

    return ;
}  

// Time Complexity:  O(N)
// Space Complexity: O(N) [ Recursive Stack Space ]
