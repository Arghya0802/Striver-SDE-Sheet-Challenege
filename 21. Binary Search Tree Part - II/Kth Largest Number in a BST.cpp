// GFG Link:  https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
// -----------------------------------------------------------------------------------

#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
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
void kthLargest(TreeNode<int>* root , int &k , int &ans)
{
    if(!root)  return ;

    kthLargest(root -> right , k , ans) ;

    k-- ;

    if(k == 0)
    {
        ans = root -> data ;  return ;
    }

    kthLargest(root -> left , k , ans) ;

    return ;
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int ans = -1 ;

    kthLargest(root , k , ans) ;

    return ans ;
}

// Time Complexity:  O(Log N)
// Space Complexity: O(Log N) [Height of the Recursive Stack Space]
