
#include <bits/stdc++.h> 
using pp = pair<int , pair<int , int>> ;

vector<int> kMaxSumCombination(vector<int> &A , vector<int> &B , int n, int k)
{
    vector<int> ans ;
	   sort(A.begin() , A.end() ) ;
    sort(B.begin() , B.end() ) ;

    priority_queue<pp> maxQ ;  maxQ.push( {A.back() + B.back() , make_pair(n - 1 , n - 1) }) ;
    
    set<pair<int , int>> visited ;  visited.insert(make_pair(n - 1 , n - 1) ) ;

    while(k--) 
    {
        auto sum = maxQ.top().first ;  int i = maxQ.top().second.first ;
        int j = maxQ.top().second.second ; maxQ.pop() ;

        ans.push_back(sum) ;

        if(visited.find(make_pair(i - 1 , j) ) == visited.end() )
        {
            int sumA = A[i - 1] + B[j] ;  visited.insert(make_pair(i - 1 , j) ) ;

            maxQ.push({sumA , make_pair(i - 1 , j) }) ; 
        }

        if(visited.find(make_pair(i , j - 1) ) == visited.end() )
        {
            int sumB = A[i] + B[j - 1] ;  visited.insert(make_pair(i , j - 1) ) ;

            maxQ.push({sumB , make_pair(i , j - 1) }) ; 
        }
    }

    return ans ;
}   

// Time Complexity:  O(K * Log K)
// Space Complexity: O(N)
