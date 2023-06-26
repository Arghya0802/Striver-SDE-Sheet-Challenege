// GFG Link: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
// --------------------------------------------------------------------------------

#include <bits/stdc++.h> 
using pp = pair<TreeNode<int> * , int> ;

/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) 
{
    if(!root)  return {} ;

    vector<int> ans ;

    queue<pp> q ;  q.push({ root , 0 }) ;

    unordered_map<int , int> map ;

    int minL = 0 ; int maxR = 0 ;

    while(!q.empty() )
    {
        int size = q.size() ;

        while(size--)
        {
            auto *node = q.front().first ;  int y = q.front().second ;
            q.pop() ;

            minL = min(minL , y) ;  maxR = max(maxR , y) ;

            if(map.find(y) == map.end() )  map[y] = node -> val ;

            if(node -> left)  q.push({ node -> left , y - 1 }) ;

            if(node -> right) q.push({ node -> right , y + 1 }) ;
        }
    }

    for(int col = minL ; col <= maxR ; col++)  ans.push_back(map[col]) ;

    return ans ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
