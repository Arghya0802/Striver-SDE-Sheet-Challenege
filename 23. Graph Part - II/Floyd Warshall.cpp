// GFG Link:  https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
// -----------------------------------------------------------------------------------------

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) 
{
    vector<vector<int>> dist(n + 1 , vector<int> (n + 1 , 1e9) ) ;

    for(int i = 1 ; i <= n ; i++)  dist[i][i] = 0 ;

    for(auto edge : edges)
    {
        int u = edge[0] ;  int v = edge[1] ; int weight = edge[2] ;

        if(u != v) dist[u][v] = weight ;
    }

    for(int k = 1 ; k <= n ; k++)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)  
            {
                if(dist[i][k] == 1e9 || dist[k][j] == 1e9)  continue ;

                dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j] ) ;
            }
        }
    }

    return dist[src][dest] ;
}

// Time Complexity:  O(N ^ 3)
// Space Complexity: O(N ^ 3)
