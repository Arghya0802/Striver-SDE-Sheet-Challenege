// LeetCode link:  https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
// ------------------------------------------------------------------------------------------------

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
#include <bits/stdc++.h>

string serializeTree(TreeNode<int> *root)
{
    if(!root)  return "" ;

    string ans = "" ;  queue<TreeNode<int> *> q ;

    q.push(root) ;

    while(!q.empty() ) 
    {
        auto *node = q.front() ;  q.pop() ;

        if(node == NULL)  ans += "#" ;

        else ans += to_string(node -> data) ;

        ans += "," ;

        if(node != NULL)
        {
            q.push(node -> left) ; q.push(node -> right) ;
        }
    }

    return ans ;
}

TreeNode<int>* deserializeTree(string &serialized)
{
    if(serialized.size() == 0)  return NULL ;

    stringstream s(serialized) ;  
    
    string str = "" ;  queue<TreeNode <int> *> q ;

    getline(s , str , ',') ;  

    TreeNode<int> *root = new TreeNode<int>(stoi(str) ) ;  q.push(root) ;

    while(!q.empty() ) 
    {
        auto *node = q.front() ; q.pop() ;

        getline(s , str , ',') ;

        if(str == "#")  node -> left = NULL ;

        else 
        {
            auto *leftNode = new TreeNode<int>(stoi(str)) ;

            node -> left = leftNode ;  q.push(leftNode) ;
        }

        getline(s , str , ',') ;

        if(str == "#")  node -> right = NULL ;

        else 
        {
            auto *rightNode = new TreeNode<int>(stoi(str)) ;

            node -> right = rightNode ;  q.push(rightNode) ;
        }
    }

    return root ;
}

// Time Complexity:  O(N) [For each serailize() and deserialize() function]
// Space Complexity: O(N)
