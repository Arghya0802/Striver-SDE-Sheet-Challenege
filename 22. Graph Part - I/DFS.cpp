// GFG link:  https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1 
// -------------------------------------------------------------------------------------------

#include <bits/stdc++.h>

void dfs(int node , vector<int> &visited , vector<vector<int>> &adj , vector<int> &path)
{
    visited[node] = 1 ;
    path.push_back(node) ;  

    for(auto neigh : adj[node])
    {
        if(!visited[neigh])  dfs(neigh , visited , adj , path) ;
    }

    return ;
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V) ;

    for(auto edge : edges)
    {
        int u = edge[0] ; int v = edge[1] ;

        adj[u].push_back(v) ;  adj[v].push_back(u) ;
    }

    vector<vector<int>> ans ;
    vector<int> visited(V , 0) ;

    for(int node = 0 ; node < V ; node++)
    {
        if(!visited[node])
        {
            vector<int> path ;

            dfs(node , visited , adj , path) ;

            ans.push_back(path) ;
        }
    }

    return ans ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
