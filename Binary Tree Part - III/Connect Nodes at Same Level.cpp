#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) 
{
    if(!root)  return ;

    queue<BinaryTreeNode< int > *> q ;  q.push(root) ;

    while(!q.empty() )
    {
        int size = q.size() ;  BinaryTreeNode< int > *prev = NULL ;

        for(int i = 0 ; i < size ; i++)
        {
            auto *node = q.front() ; q.pop() ;

            if(i > 0)  prev -> next = node ;

            prev = node ;

            if(node -> left)  q.push(node -> left) ;

            if(node -> right)  q.push(node -> right) ;
        }
    }

    return ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
