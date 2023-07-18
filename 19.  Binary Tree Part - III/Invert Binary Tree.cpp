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
typedef TreeNode<int> * Tree;

void solve(Tree root , Tree parent , Tree leaf , bool & isFound , Tree &ans)
{
    if(!root)  return ;

    if(root -> data == leaf -> data)
    {
        root -> left = parent ;

        isFound = 1 ; ans = root ;

        return ;
    }

    solve(root -> left , root , leaf , isFound , ans) ;

    if(isFound)
    {
        root -> left = parent ;  return ;

    }

    solve(root -> right , root , leaf , isFound , ans) ;

    if(isFound)
    {

        if(root ->left) root -> right = root -> left ;

        else  root -> right = NULL ;

        root -> left = parent ;  return;
    }

}

TreeNode<int> * invertBinaryTree(TreeNode<int> *root , TreeNode<int> *leaf)
{

    bool isFound = 0 ;  Tree ans = NULL ;

    solve(root , NULL , leaf , isFound , ans) ;

    return ans; 

}

// Time Complexity:  O(N)
// Space Complexity: O(N)
