// LeetCode Link:  https://leetcode.com/problems/same-tree/
// ---------------------------------------------------------

#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
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

***********************************************************/
bool isSymmetric(BinaryTreeNode<int> *p , BinaryTreeNode<int> *q)
{
    if(p == NULL && q == NULL)  return true ;

    if(p == NULL || q == NULL)  return false ;

    if(p -> data != q -> data)  return false ;
    
    bool leftAns = isSymmetric(p -> left , q -> left) ;

    bool rightAns = isSymmetric( p-> right , q -> right) ;

    return leftAns && rightAns ;
}

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) 
{
    return isSymmetric(root1, root2) ; 
}

// Time Complexity:  O(N)
// Space Complexity: O(N) [Recursive Stack Space]
