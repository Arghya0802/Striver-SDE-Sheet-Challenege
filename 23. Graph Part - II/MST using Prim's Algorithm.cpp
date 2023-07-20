// GFG Link:  https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
// -------------------------------------------------------------------------------

#include <bits/stdc++.h> 
using pp = pair<int , int> ;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<int,int>>adj[n + 1] ;

    for(int i = 0 ; i < m ; i++)
    {
        int u = g[i].first.first ; int v = g[i].first.second ; int wt = g[i].second ;

        adj[u].push_back(make_pair(v , wt) ) ; adj[v].push_back(make_pair(u , wt)) ;
    }

    priority_queue<pp , vector<pp> , greater<pp>> minQ ;

    vector <int> dist(n + 1 ,INT_MAX) ; vector <int> parent(n + 1 ,-1) ;

    vector<int>vis(n + 1 , 0) ;  minQ.push(make_pair(0 , 1) ) ;

    dist[1] = 0 ;  parent[1] = -1 ;

    while(!minQ.empty() )
    {
        int dis = minQ.top().first ;  int node = minQ.top().second ;

        minQ.pop() ;  vis[node] = 1 ;

        for(auto it: adj[node] )
        {
            int adjNode = it.first ; int wt = it.second ;

            if(!vis[adjNode] && dist[adjNode] > wt)
            {
                dist[adjNode] = wt ;  parent[adjNode] = node ;

                minQ.push(make_pair(wt , adjNode) ) ;
            }
        }
    }

    vector<pair<pp , int>> ans ;

    for(int i = 2 ;i <= n ; i++)  ans.push_back(make_pair(make_pair(parent[i] , i) , dist[i] ) ) ;

    return ans ;
}

// Time Complexity:  O(E * Log E)
// Space Complexity: O(V) + O(E)
