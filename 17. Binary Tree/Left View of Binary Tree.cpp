// GFG Link:  https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
// ---------------------------------------------------------------------------------

// Use Level Order Traversal and for every level store the first element that we encounter

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

vector<int> getLeftView(TreeNode<int> *root)
{
    if(!root)  return {} ;
    
    vector<int> ans ;
    queue<TreeNode<int> *> q ;  q.push(root) ;

    while(!q.empty() )
    {
        int size = q.size() ;  int leftEle = -1 ;

        for(int i = 0 ; i < size ; i++)
        {
            auto node = q.front() ;  q.pop() ;

            if(i == 0)  leftEle = node -> data ;

            if(node -> left)   q.push(node -> left) ;

            if(node -> right)  q.push(node -> right) ;
        }

        ans.push_back(leftEle) ;
    }

    return ans ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
