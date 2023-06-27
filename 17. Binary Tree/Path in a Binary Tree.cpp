#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/


bool preOrder(TreeNode<int> *root , int x , vector<int> &path)
{
	if(!root)  return false ;

	if(root -> data == x)  
	{
		path.push_back(x) ;  return true ;
	}

	path.push_back(root -> data) ;

	if(preOrder(root -> left , x , path) )  return true ;

	if(preOrder(root -> right , x , path) ) return true ;

	path.pop_back() ;  return false ;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
	vector<int> ans ;  vector<int> path ;

	preOrder(root , x , ans) ;

	return ans ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N) [Recursive Stack Space]
