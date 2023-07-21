// GFG Link:  https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
// -------------------------------------------------------------------------------

#include <bits/stdc++.h>

static bool cmp(vector<int> &A , vector<int> &B)
{
	return A[2] < B[2] ;
}

void update(vector<int> &rank , vector<int> &parent , int n)
{
	for(int i = 1 ; i <= n ; i++)
	{
		rank[i] = 0 ;  parent[i] = i ;
	}
}

int findParent(int node , vector<int> &parent)
{
	if(parent[node]== node)  return node ;

	return parent[node] = findParent(parent[node] , parent) ;
}


void unionSet(int u,int v,vector<int> &parent,vector<int> &rank)
{

	u = findParent(u , parent) ; v = findParent(v , parent) ;

	if(rank[u]>rank[v]) parent[v] = u ;

	else if(rank[u]<rank[v]) parent[u] = v ;

	else 
	{
		parent[v] =u ; rank[u]++ ;
	}
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) 
{	
	sort(graph.begin() , graph.end() , cmp) ;

	vector<int> rank(n + 1) ;  vector<int> parent(n + 1) ;

	update(rank , parent , n) ;  int ans = 0 ;

	for(int i = 0 ; i< m ; i++)
	{
		int u = findParent(graph[i][0] , parent) ;
		int v = findParent(graph[i][1] , parent) ;  int wt = graph[i][2] ;

		if(u != v)
		{
			ans += wt ;  unionSet(u ,v , parent , rank) ;
		}

	}

	return ans ;
}

// Time Complextiy:  O(N + E) + O(E * Log E) + O(E * 4α * 2) 
// Space Complexity: O(N) + O(N) + O(E)
