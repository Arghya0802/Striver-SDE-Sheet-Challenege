// GFG Link:  https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
// ------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h> 
using pp = pair<int , int> ;

vector<int> dijkstra(vector<vector<int>> &graph, int V , int edges, int source) 
{
    vector<vector<pp>> adj(V) ;

    for(auto it : graph)
    {
        int u = it[0] ; int v = it[1] ;  int weight = it[2] ;

        adj[u].push_back(make_pair(v , weight) ) ;
        adj[v].push_back(make_pair(u , weight) ) ;

    }

    vector<int> dist(V , INT_MAX) ;  dist[source] = 0 ;

    priority_queue<pp , vector<pp> , greater<pp>> minQ ;  minQ.push(make_pair(0 , source) ) ;

    while(!minQ.empty() ) 
    {
        int node = minQ.top().second ;  int dis = minQ.top().first ;
        minQ.pop() ;

        for(auto it : adj[node] ) 
        {
            int edgeWeight = it.second ; int adjNode = it.first ;

            if(dis + edgeWeight < dist[adjNode] ) 
            {
                dist[adjNode] = dis + edgeWeight ;

                minQ.push({ dis + edgeWeight , adjNode } ) ;
            }
        }
    }

    return dist ;
}

// Time Complexity:  O(E * Log V)
// Space Complexity: O(V)
