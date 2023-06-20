// GFG Link:  https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#
// ---------------------------------------------------------------------------------------

/* Appraoch [Think Like a Recursion problem instead of Graph Traversal]
1. We use a colors[n] array to keep track of which node has been colored by which color out of the M colors we have been given.
2. To avoid coloring adjacent nodes, we use the adjacency matrix or adjacency list to check if the neighbors of the current node are already colored with the same color or not. 
3. If not, we can color that particular node with i-th color and ask recursion to check if we can color the other available nodes.
4. If not, we try for the other possible colors and at the end return true or false accordingly. 
5. Make sure we return back directly if any one of the possible combinations is giving us the correct answer else we must backtrack and undo the change we did, that is, remove the color from that particular node.
*/

#include <bits/stdc++.h> 

bool isSafe(vector<vector<int>> &adj , vector<int> &colors , int node , int nColor)
{
    int n = adj.size() ;

    for(int neigh = 0 ; neigh < n ; neigh++)
    {
        if(node != neigh && adj[node][neigh] == 1 && colors[neigh] == nColor)  return false;
    }

    return true ;
}

bool canColorNodes(int node , int n , int m , vector<int> &colors , vector<vector<int>> &adj)
{
    if(node == n)  return true ; // Base Case

    for(int i = 1 ; i <= m ; i++)
    {
        if(isSafe(adj , colors , node , i) ) // If we can use that particular color on the given Node
        {
            colors[node] = i ; // We color the Node with that color
            
            // And asks Recursion to do rest of the task

            // If recursion returns true, it means we have found a correct possible combination, so we directly return true
            if( canColorNodes(node + 1 , n , m , colors, adj) )  return true ;

            colors[node] = 0 ; // Otherwise, we backtrack and undo the change we did
        }
    }

    return false ; // If no possible coloring is possible for the node, we return false ;
}

string graphColoring(vector<vector<int>> &mat, int m) 
{
    int n = mat.size() ;

    vector<int> colors(n) ;

    return canColorNodes(0 , n , m , colors , mat) ? "YES" : "NO" ;
}

// Time Complexity:  O(M ^ N)
// Space Complexity: O(N) [For Recursive Stack Space + Colors[] array]
