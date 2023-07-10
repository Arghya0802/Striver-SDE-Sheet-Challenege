// LeetCode:  https://leetcode.com/problems/reverse-words-in-a-string/description/
// ------------------------------------------------------------------------------

void removeSpaces(string &s , int n)
{
	int i = 0 ;

	while(i < n && s[i] == ' ')  i++ ;

	s = s.substr(0 , i) ;

	i = s.size() - 1 ;

	while(i >= 0 && s[i] == ' ')  i-- ;
	
	s = s.substr(0 , i + 1) ;

	
	return ;
}

string reverseString(string &str)
{
	int n = str.size() ;
	
	string ans = "" ;  string wd = "" ;

	str += ' ' ;  vector<string> temp ;
	
	for(int i = 0 ; i < str.size() ; i++)
	{
		char ch = str[i] ;

		if(ch != ' ')  wd += ch ;

		else
		{
			if(wd.size() > 0)  temp.push_back(wd) ;

			wd = "" ;
		}
	}

	reverse(temp.begin() , temp.end() ) ;

	for(auto s : temp)  
	{
		ans += s ; ans += ' ' ;
	}

	ans.pop_back() ;

	return ans ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
