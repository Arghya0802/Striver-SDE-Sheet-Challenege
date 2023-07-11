// LeetCode link: https://leetcode.com/problems/course-schedule/
// -----------------------------------------------------------

#include <bits/stdc++.h>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) 
{
    vector<vector<int>> adj(n + 1) ;
    vector<int> inDegree(n + 1 , 0) ;

    for(auto edge : edges)
    {
        int u = edge.first ; int v = edge.second ;

        adj[u].push_back(v) ;  inDegree[v] += 1 ;
    }

    queue<int> q ; vector<int> topoSort ;

    for(int node = 1 ; node <= n ; node++)
    {
        if(!inDegree[node])
        {
          q.push(node) ;  topoSort.push_back(node) ;
        }
    }

    while(!q.empty() )
    {
        int node = q.front() ;  q.pop() ;

        for(int neigh : adj[node])
        {
            inDegree[neigh] -= 1 ;

            if(inDegree[neigh] == 0)
            {
                q.push(neigh) ;  topoSort.push_back(neigh) ;
            }
        }
    }

    return topoSort.size() == n ? false : true ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
