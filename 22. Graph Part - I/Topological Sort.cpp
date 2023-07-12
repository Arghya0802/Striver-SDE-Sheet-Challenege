// GFG Link:  https://practice.geeksforgeeks.org/problems/topological-sort/1
// --------------------------------------------------------------------------

#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) 
{
    vector<vector<int>> adj(v) ;   vector<int> inDegree(v , 0) ;

    for(auto edge : edges)
    {
        int u = edge[0] ; int v = edge[1] ;

        adj[u].push_back(v) ;

        inDegree[v] += 1 ;
    }

    queue<int> q ;  

    for(int node = 0 ; node < v ; node++)
    {
        if(inDegree[node] == 0)  q.push(node) ;
    }

    vector<int> topoSort ;

    while(!q.empty() )
    {
        int node = q.front() ;  q.pop() ;

        topoSort.push_back(node) ;

        for(int neigh : adj[node])
        {
            inDegree[neigh] -= 1 ;

            if(inDegree[neigh] == 0)  q.push(neigh) ;
        }
    }

    return topoSort ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)

