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

int floorInBST(TreeNode<int> * root, int key)
{
    int floorOfX = INT_MIN ;

    while(root)
    {
        if(root -> val == key)  return root -> val ;

        if(root -> val < key)
        {
            floorOfX = root -> val ;
            root = root -> right ;
        }

        else root = root -> left ;
    }

    return floorOfX ;
}

// Time Complexity:  O(Log N)
// Space Complexity: O(1)
