vector<int> stringMatch(string &text , string &pattern) 
{
	int n = pattern.size() ;  int m = text.size() ; 

    vector<int> ans ;

    for(int i = 0 ; i < m ; i++)
    {
        if(text[i] == pattern[0] && (i + n - 1) < m)
        {
            string str = text.substr(i , n) ;

            if(str == pattern)  ans.push_back(i + 1) ;

        }

    }
    
    return ans;
}

// Time Complexity:  O(M * N)
// Space Complexity: O(1) [Excluding the space to store the answer indices]
