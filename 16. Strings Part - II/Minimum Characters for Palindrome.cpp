

int minCharsforPalindrome(string str) 
{
	int low = 0 ;  int high = str.size() - 1 ;

	int ind = high ;  int cnt = 0 ;

	while(low < high)
	{
		if(str[low] == str[high] )
		{
			low++ ;  high-- ;
		}

		else
		{
			low = 0 ;  ind-- ;

			high = ind ;  cnt++ ;
		}
	}
	
	return cnt ;
}

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(1)
