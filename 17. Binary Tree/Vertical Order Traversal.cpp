// LeetCode Link:  https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
// ----------------------------------------------------------------------------------------------------

// Approach: Store (minL, minR) and use a map to store all such elements

#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

using pp = pair<TreeNode <int> * , pair<int , int>> ;
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans ;

    if(!root)  return {} ;

    unordered_map<int , unordered_map<int , vector<int>> > map ;

    queue<pp> q ;  q.push({ root , { 0 , 0 }}) ;

    int minL = 0 , maxR = 0 , maxLvl = 0 ;

    while(!q.empty() )
    {
        auto *node = q.front().first ;
        int x = q.front().second.first ;  int y = q.front().second.second ;
        q.pop() ;

        minL = min(minL , y) ;  maxR = max(maxR , y) ;  
        maxLvl = max(maxLvl , x) ;

        map[y][x].push_back(node -> data) ;

        if(node -> left)  q.push({ node -> left , { x + 1 , y - 1 }}) ;

        if(node -> right) q.push({ node -> right , { x + 1 , y + 1 }}) ;
    }

    for(int col = minL ; col <= maxR ; col++)
    {
        vector<int> temp ;
        for(int row = 0 ; row <= maxLvl ; row++)
        {
            if(map[col].find(row) != map[col].end() )
            {
                for(auto it : map[col][row])  ans.push_back(it) ;

                // ans.push_back(temp) ;
            }
        }

        // ans.push_back(temp) ;
    }

    return ans ;
}

// Time Complexity:  O(N * Log N * LogN * LogN)
// Space Complexity: O(N)
