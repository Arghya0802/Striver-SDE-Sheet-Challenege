// GFG Link:  https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0?fbclid=IwAR2_lL0T84DnciLyzMTQuVTMBOi82nTWNLuXjUgahnrtBgkphKiYk6xcyJU
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) 
{
    vector<int> dist(n + 1 , 1e9) ;  dist[src] = 0 ;

    for(int i = 0 ; i < n ; i++)
    {
        for(auto it : edges)
        {
            int u = it[0] ;  int v = it[1] ; int edgeWeight = it[2] ;

            if(dist[u] != 1e9 && edgeWeight + dist[u] < dist[v] )  
                dist[v] = dist[u] + edgeWeight ;
        }
    }

    return dist[dest] ;
}

// Time Complexity:  O(V * E)
// Space Complexity: O(V)
