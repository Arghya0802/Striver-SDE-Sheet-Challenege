#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    int n = arr.size() ; vector<int> ans ;

    unordered_map<int , int> hashMap ;

    int end = 0 ;  int start = 0 ; int cnt = 0 ;

    while(start < k)
    {
        int accept = arr[start] ; start++ ;

        if(hashMap.find(accept) == hashMap.end() )  cnt++ ;

        hashMap[accept] += 1 ;
    }

    for(; start < n ; start++)
    {
        ans.push_back(cnt) ;

        int discard = arr[end] ; end++ ;

        hashMap[discard] -= 1 ; 

        if(hashMap[discard] == 0)  
        {
            hashMap.erase(discard) ; cnt-- ;
        }
        
        int accept = arr[start] ; 

        if(hashMap.find(accept) == hashMap.end() )  cnt++ ;

        hashMap[accept] += 1 ;
    }

    ans.push_back(cnt) ;
    
    return ans ;
}

// Time Complexity:  O(N)
// Space Complexity: O(1)
