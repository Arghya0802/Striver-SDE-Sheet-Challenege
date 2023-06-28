// LeetCode Link:  https://leetcode.com/problems/diameter-of-binary-tree/description/
// ----------------------------------------------------------------------------------

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

int maxDepth(TreeNode<int> *root , int &ans)
{
    if(!root)  return 0 ;

    int lh = maxDepth(root -> left , ans)  ;
    int rh = maxDepth(root -> right , ans)  ;

    ans = max(ans , lh + rh) ;

    return 1 + max(lh , rh) ;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	int ans = 0 ;

    maxDepth(root , ans) ;

    return ans ;
}

// Time Complexity:  O(N)
// Space Complexity:  O(N) [Recursive Stack Space]
