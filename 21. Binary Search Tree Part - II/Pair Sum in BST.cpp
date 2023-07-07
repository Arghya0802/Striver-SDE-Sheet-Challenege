// LeetCode Link:  https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// -------------------------------------------------------------------------

#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
bool findPairSum(BinaryTreeNode<int> *root , int k , unordered_map<int , int> &map)
{
    if(!root)  return false ;

    if(map.find(k - root -> data) != map.end() )  return true ;

    map[root -> data] += 1 ;

    bool leftAns  = findPairSum(root -> left , k , map) ;

    bool rightAns = findPairSum(root -> right , k , map) ;

    return leftAns || rightAns ;
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    unordered_map<int , int> map ;

    return findPairSum(root , k , map) ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
