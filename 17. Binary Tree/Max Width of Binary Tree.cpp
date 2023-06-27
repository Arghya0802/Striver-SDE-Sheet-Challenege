#include <bits/stdc++.h> 
using ll = long long int ;
using pp = pair<TreeNode<int> * , ll> ;
/************************************************************

    Following is the TreeNode class structure

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

int getMaxWidth(TreeNode<int> *root)
{
    if(!root)  return 0 ;

    int maxWidth = 0 ;  

    queue<pp> q ;  q.push(make_pair(root , 0 ) ) ;

    while(!q.empty() )
    {
        int size = q.size() ;  ll minVal = q.front().second ; ll maxVal = 0 ;

        maxWidth = max(maxWidth , size) ;

        while(size--)
        {
            auto *node = q.front().first ; ll val = q.front().second ;  q.pop() ;

            maxVal = max(maxVal , val) ;  val -= minVal ;

            if(node -> left)   q.push(make_pair(node -> left , 2 * val) ) ;

            if(node -> right)  q.push(make_pair(node -> right , 2 * val + 1) ) ;
        }

        // int width = maxVal - minVal + 1 ;  maxWidth = max(maxWidth , width) ;
    }

    return  maxWidth ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
