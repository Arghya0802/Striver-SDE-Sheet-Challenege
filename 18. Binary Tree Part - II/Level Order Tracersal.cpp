// LeetCode Link:  https://leetcode.com/problems/binary-tree-level-order-traversal/
// ----------------------------------------------------------------------------------

#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
   if(!root)  return {} ;

    queue<BinaryTreeNode<int>* > q  ;  q.push(root) ;
    vector<int> ans ;

    while(!q.empty() )
    {
        int size = q.size()  ;

        while(size--)
        {
            auto *node = q.front()  ;  q.pop() ;

            ans.push_back(node -> val)  ;

            if(node -> left)  q.push(node -> left) ;
            if(node -> right)  q.push(node -> right) ;
        }
    }

    return ans ;
}

// Time Complexity:   O(N)
// Space Complexity:  O(N)
