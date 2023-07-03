// LeetCode:  https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// ------------------------------------------------------------------------------------

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int> *constructBST(int low , int high , vector<int> &arr)
{
    if(low > high)  return NULL ;

    if(low == high)
    {
        TreeNode<int> *leaf = new TreeNode<int> (arr[low]) ;

        return leaf ;
    }

    int mid = low + (high - low) / 2 ;

    TreeNode<int> *root = new TreeNode<int> (arr[mid]) ;

    root -> left = constructBST(low , mid - 1 , arr) ;

    root -> right = constructBST(mid + 1 , high , arr) ;

    return root ;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return constructBST(0 , n - 1 , arr) ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N) [Recursive Stack space
