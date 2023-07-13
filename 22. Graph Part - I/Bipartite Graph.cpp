// LeetCode link:  https://leetcode.com/problems/is-graph-bipartite/
// -----------------------------------------------------------------

#include<bits/stdc++.h>

bool dfs(int node, int color , vector<int> &colors , vector<vector<int>> &adj)
{
	colors[node] = color ;  int nextColor = 1 - color ;

	for(auto neigh : adj[node])
	{
		if(colors[neigh] == -1)
		{
			if(dfs(neigh , nextColor , colors , adj) == false)  return false ;
		}

		else if(colors[neigh] == color)  return false ;
	}

	return true ;
}

bool isGraphBirpatite(vector<vector<int>> &edges) 
{
	int n = edges.size() ;  vector<vector<int>> adj(n) ;

	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			if(i == j || edges[i][j] == 0)  continue ;

			adj[i].push_back(j) ; adj[j].push_back(i) ;
		}
	}

	vector<int> colors(n , -1) ;

	for(int node = 0 ; node < n ; node++)
	{
		if(colors[node] == -1)
		{
			if(dfs(node , 0 , colors , adj) == true)  return true ;
		}
	}

	return false ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N) 
