// LeetCode link:  https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
// -------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using pp = pair<int , pair<int , int>> ;

struct Node
{
    Node *links[2] ;

    bool containsKey(int bit)
    {
        return links[bit] != NULL ;
    }

    void put(int bit , Node *node)
    {
        links[bit] = node ;
    }

    Node *get(int bit)
    {
        return links[bit] ;
    }
};

class Trie
{
    private:
    Node *root ;

    public:

    Trie()
    {
        root = new Node() ;
    }
    
    void insert(int num)
    {
        Node *node = root ;

        for(int i = 31 ; i >= 0 ; i--)
        {
            int bit = (num >> i) & 1 ;

            if(!node -> containsKey(bit) )  node -> put(bit , new Node() ) ;

            node = node -> get(bit) ;
        }
    }

    int maxXOR(int num)
    {
        Node *node = root ;  int maxNum = 0 ;

        for(int i = 31 ; i >= 0 ; i--)
        {
            int bit = (num >> i) & 1 ;

            if( node -> containsKey(1 - bit) )
            {
                maxNum = maxNum | (1 << i) ;  node = node -> get(1 - bit) ;
            }

            else  node = node -> get(bit) ;
        }

        return maxNum ;
    }
};

static bool cmp(pp &A , pp &B)
{
	return A.second.first < B.second.first ;
}

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
	Trie *trie = new Trie() ;

	int m = queries.size() ;  vector<int> ans(m , -1) ;

	sort(arr.begin() , arr.end() ) ;  vector<pp> offQuery ;

	for(int i = 0 ; i < m ; i++) 
	{
		int x = queries[i][0] ; int val = queries[i][1] ;  
		
		offQuery.push_back(make_pair(x , make_pair(val , i) ) ) ;
	}

	sort(offQuery.begin() , offQuery.end() , cmp) ;	

	int n = arr.size() ;  int i = 0 ;

	for(auto query : offQuery)
	{
		int x = query.first ; int val = query.second.first ; int ind = query.second.second ;

		while(i < n && arr[i] <= val)  
		{
			trie -> insert( arr[i] ) ;  i++ ;
		}

		if(i == 0)  continue ;

		ans[ind] = trie -> maxXOR(x) ;
	}

	return ans ;
}

// Time Complexity:  O(N + Q) [Q is the number of queries]
// Space Complexity: O(Q) [Q is the number of queries]
