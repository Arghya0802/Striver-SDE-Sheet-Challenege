// LeetCode Link:  https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// ---------------------------------------------------------------------------

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
void kthSmallest(TreeNode<int> *root , int &k , int &ans)
{
    if(!root)  return ;

    kthSmallest(root -> left , k , ans) ;

    k-- ;

    if(k == 0)
    {
        ans = root -> data ;  return ;
    }

    kthSmallest(root -> right , k , ans) ;

    return ;
}

int kthSmallest(TreeNode<int> *root, int k)
{
    int ans = -1 ;

	kthSmallest(root , k , ans) ;

    return ans ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N) [ Only Recursive Stack Space is used ]
