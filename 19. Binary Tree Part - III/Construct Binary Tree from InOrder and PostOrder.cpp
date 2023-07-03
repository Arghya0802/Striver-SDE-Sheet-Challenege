// LeetCode Link:  https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// ---------------------------------------------------------------------------------------------------------

/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include <bits/stdc++.h>

TreeNode<int> *buildTree(int low , int high , int &ind , vector<int> &postOrder , unordered_map<int , int> &map)
{
     if(ind < 0)  return NULL ;

     if(low == high)
     {
          TreeNode<int> *leaf = new TreeNode<int> (postOrder[ind]) ; ind-- ;

          return leaf ;
     }

     if(low > high)  return NULL ;

     int val = postOrder[ind] ;  ind-- ;

     TreeNode<int> *root = new TreeNode<int> (val) ;

     int mid = map[val] ;

     root -> right = buildTree(mid + 1 , high , ind , postOrder , map) ;

     root -> left = buildTree(low , mid - 1 , ind , postOrder , map) ;

     return root ;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	unordered_map<int , int> inOrderMap ;  int n = inOrder.size() ;

     for(int i = 0 ; i < n ; i++)  inOrderMap[inOrder[i]] = i ;

     int ind = n - 1 ;

     return buildTree(0 , n - 1 , ind , postOrder , inOrderMap) ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N) [We are using the InOrderMap]
