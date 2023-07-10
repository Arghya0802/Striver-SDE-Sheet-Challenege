// GFG Link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// ------------------------------------------------------------------------------

#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<vector<int>> adj(vertex) ;

    for(auto edge : edges)
    {
        int u = edge.first ; int v = edge.second ;

        adj[u].push_back(v) ;  adj[v].push_back(u) ;
    }

    for(int i = 0 ; i < vertex ; i++) sort(adj[i].begin() , adj[i].end() ) ; 


    vector<int> visited(vertex , 0) ;  visited[0] = 1 ;

    queue<int> q ; q.push(0) ;

    vector<int> ans ;  

    while(!q.empty() )
    {
        int node = q.front() ;  q.pop() ;

        ans.push_back(node) ;

        for(int neigh : adj[node])
        {
            if(!visited[neigh])
            {
                visited[neigh] = 1 ; q.push(neigh) ;
            }
        }
    }

    // for(int nums : ans)  cout << nums << " " ;
    // cout << endl ;

    for(int node = 0 ; node < vertex ; node++) 
    {
        if(!visited[node])  ans.push_back(node) ;
    }
    
    return ans ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
