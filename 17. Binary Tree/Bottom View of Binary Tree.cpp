// GFG Link: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
// ----------------------------------------------------------------------------------

/* Level Order Traversal and store the last node we visit for a particular column
PS: Imagine the Tree as a Matrix and the solution will be easier to visualize
*/

#include <bits/stdc++.h> 
using pp = pair<BinaryTreeNode<int> * , int> ;

/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root)
{

    if(!root)  return {} ;

    queue<pp> q ;  q.push({root , 0}) ;    

    int minL = 0 ; int maxR = 0 ;

    unordered_map<int , int> map ;

    while(!q.empty() ) 
    {
        int size = q.size() ;

        while(size--)
        {
            auto node = q.front().first ;  int y = q.front().second ; q.pop() ;

            minL = min(minL , y) ; maxR = max(maxR , y) ;

            map[y] = node -> data ;

            if(node -> left)  q.push({ node -> left , y - 1 }) ;
            if(node -> right) q.push({ node -> right , y + 1 }) ;
        }
    }
    
    vector<int> ans ;

    for(int col = minL ; col <= maxR ; col++)  ans.push_back(map[col]) ;

    return ans ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
