// LeetCode Link:  https://leetcode.com/problems/course-schedule/
// --------------------------------------------------------------

#include<bits/stdc++.h>

bool dfs(int node , int parent , vector<int> &visited , vector<vector<int>> &adj)
{
    visited[node] = 1 ;

    for(int neigh : adj[node])
    {
        if(!visited[neigh])  
        {
            if(dfs(neigh , node , visited , adj) == true)  return true ;
        }

        else if(neigh != parent)  return true ;
    }

    return false ;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> adj(n + 1) ;

    for(auto edge : edges)
    {
        int u = edge[0] ; int v = edge[1] ;

        adj[u].push_back(v) ;  adj[v].push_back(u) ;
    }

    vector<int> visited(n + 1 , 0) ;

    for(int node = 1 ; node <= n ; node++)
    {
        if(!visited[node])
        {
            if(dfs(node , -1 , visited , adj) == true)  return "Yes" ;
        }
    }

    return "No" ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
