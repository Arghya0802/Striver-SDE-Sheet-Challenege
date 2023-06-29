// LeetCode Link:  https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// ---------------------------------------------------------------------------------------

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    if(!root)  return {} ;

    vector<int> ans ; bool isEven = true ; 
    
    queue<BinaryTreeNode<int> *> q ;  q.push(root) ;

    while(!q.empty() )
    {
        int size = q.size() ;  vector<int> nums ;

        while(size--)
        {
            auto *node = q.front() ;  q.pop() ;

            nums.push_back(node -> data) ;

            if(node -> left)   q.push(node -> left)  ;

            if(node -> right)  q.push(node -> right) ;
        }

        if(isEven)
        {
            for(auto it : nums)  ans.push_back(it) ;
        }

        else
        {
            reverse(nums.begin() , nums.end() ) ;

            for(auto it : nums)  ans.push_back(it) ;
        }

        isEven = !isEven ;
    }

    return ans ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
