// LeetCode Link:  https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/description/
// -------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>

void dfs(int node , vector<int> &vis , vector<vector<int>> &adj , stack<int> &st)
{
    vis[node] = 1 ;
    
    for(auto neigh: adj[node] )
    {
        if(!vis[neigh] )  dfs(neigh , vis , adj , st) ;
    }

    st.push(node) ;
}

void dfs2(int node , vector<int> &vis , vector<vector<int>> &adjRev , vector<int> &topPush)
{
    vis[node] = 1 ;

    for(auto neigh : adjRev[node] )
    {
        if(!vis[neigh] )  dfs2(neigh , vis , adjRev , topPush) ;
    }

    topPush.push_back(node) ;
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(n) ;

    for(auto it : edges)
    {
        int u = it[0] ; int v = it[1] ;

        adj[u].push_back(v) ;  
    }

    stack<int>st ; vector<int> visited(n , 0) ;

    for(int node = 0 ; node <  n ; node++)
    {
        if(!visited[node] ) dfs(node , visited , adj , st) ;
    }

    vector<vector<int>> adjRev(n) ;

    for(int node = 0 ; node < n ; node++)
    {
        visited[node] = 0 ;

        for(auto neigh : adj[node] )  adjRev[neigh].push_back(node) ;
    }

    vector<vector<int>> ans ;
    
    while(!st.empty() )
    {
        int topNode = st.top() ;  st.pop() ;

        vector<int> topPush;
        
        if(!visited[topNode] )  dfs2(topNode , visited , adjRev , topPush) ;
        
        ans.push_back(topPush) ;
    }
    
    return ans ;
}

// Time Complexity:  O(V + E)
// Space Complexity: O(V + E)
