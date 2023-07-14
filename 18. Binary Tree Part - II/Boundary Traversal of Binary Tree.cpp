#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
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

bool isLeaf(TreeNode<int> *node)
{
    if(!node -> left && !node -> right)  return true ;

    return false ;
}

void addLeftBoundary(TreeNode<int> *node , vector<int> &ans)
{
    // TreeNode<int> *node = root -> left ;

    while(node)
    {
        if(!isLeaf(node) )  ans.push_back(node -> data) ;

        if(node -> left)  node = node -> left ;

        else node = node -> right ;
    }
}

void addLeaves(TreeNode<int> *root , vector<int> &ans)
{
    // if(!root)  return ;

    if(isLeaf(root) )  
    {
        ans.push_back(root -> data) ;  return ;
    }

    if(root -> left) addLeaves(root -> left , ans) ;

    if(root -> right) addLeaves(root -> right , ans) ;

    return ;
}

void addRightBoundary(TreeNode<int> *node , vector<int> &ans)
{
    // TreeNode<int> *node = node -> right ; 
    stack<int> st ; 

    while(node)
    {
        if(!isLeaf(node) )  st.push(node -> data) ;

        if(node -> right)  node = node -> right ;

        else node = node -> left ;
    }

    while(!st.empty() )
    {
        ans.push_back(st.top() ) ;  st.pop() ;
    }

    return ;
}

vector<int> traverseBoundary(TreeNode<int>* root)
{
    if(!root)  return {} ;
    
    vector<int> ans ;  

    if(!isLeaf(root) ) ans.push_back(root -> data) ;

    addLeftBoundary(root -> left , ans) ;

    addLeaves(root , ans) ;

    addRightBoundary(root -> right , ans) ;

    return ans ;
}

// Time Complexity:  O(3 * N)
// Space Complexity: O(N)
