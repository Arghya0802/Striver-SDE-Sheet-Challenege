// LeetCode link:  https://leetcode.com/problems/clone-graph/description/
// ----------------------------------------------------------------------

#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

graphNode *cloneGraph(graphNode *root , unordered_map<graphNode *, graphNode *> &map)
{
	if(!root)  return NULL ;

	if(map.find(root) != map.end() )  return map[root] ;

	graphNode *copyNode = new graphNode(root -> data) ;

	map[root] = copyNode ;

	for(auto neigh : root -> neighbours)
	{
		graphNode *copyNeigh = cloneGraph(neigh , map) ;

		copyNode -> neighbours.push_back(copyNeigh) ;
	}

	return copyNode ;
}

graphNode *cloneGraph(graphNode *node)
{
    unordered_map<graphNode * , graphNode *> map ;

	return cloneGraph(node , map) ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N) [Map + Recursive stack space]
