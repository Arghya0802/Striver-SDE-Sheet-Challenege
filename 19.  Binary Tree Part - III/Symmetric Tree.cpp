// LeetCode link:  https://leetcode.com/problems/symmetric-tree/
// -------------------------------------------------------------

/*****************************************************

    Following is the Binary Tree node structure:
    
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
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool isSameTree(BinaryTreeNode<int> *p ,BinaryTreeNode<int> *q)
{
    if(p == NULL && q == NULL)  return true ;

    if(p == NULL || q == NULL)  return false ;
    
    if(p -> data != q -> data)  return false ;
    
    bool leftAns  = isSameTree(p -> left , q -> right) ;
    bool rightAns = isSameTree(p -> right , q -> left) ;

    return leftAns && rightAns ;
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(!root)  return true ;
    
    if(root -> left == NULL && root -> right == NULL)  return false ;
  
    return isSameTree(root -> left , root -> right) ;  
}

// Time Complexity:  O(N)
// Space Complexity: O(N) [Recursive stack apace]
