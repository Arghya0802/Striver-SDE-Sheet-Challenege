// LeetCode Link:  https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
// ----------------------------------------------------------------------------------------


#include <bits/stdc++.h> 
using ll = long long int ;
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

ll maxPathSum(TreeNode<int> *root , ll &ans)
{
    if(!root)  return 0 ;

    ll leftPath = maxPathSum(root -> left , ans) ;

    ll rightPath = maxPathSum(root -> right , ans) ;

    if(leftPath < 0)  leftPath = 0 ;

    if(rightPath < 0)  rightPath = 0 ;

    ans = max(ans , leftPath + (ll) root -> val + rightPath) ;

    return root -> val + max(leftPath , rightPath) ;
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    if(!root)  return -1 ;
    if(!root -> left && !root -> right)  return -1 ;
    if(!root -> left || !root -> right)  return -1 ;

    ll ans = INT_MIN ;

    maxPathSum(root , ans) ;

    return ans ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N) [Recursive stack space]
