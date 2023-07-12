// LeetCode link:  https://leetcode.com/problems/count-and-say/
// ------------------------------------------------------------

#include <bits/stdc++.h> 

string writeAsYouSpeak(int n) 
{
	string ans = "1" ;

	for(int i = 1 ; i < n ; i++)
	{
		string curr = "" ; 
		char prev = ans[0] ; int cnt = 0 ;

		for(int j = 0 ; j < ans.size() ; j++)
		{
			if(prev == ans[j])  cnt++ ;

			else
			{
				curr += to_string(cnt) ;  curr += prev ;
				prev = ans[j] ;  cnt = 1 ;
			}
		}

		curr += to_string(cnt) ;  curr += prev ;

		ans = curr ;
	}	

	return ans ;
}

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N) [For storing the ans string]
