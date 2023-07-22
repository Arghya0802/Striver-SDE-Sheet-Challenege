int zAlgorithm(string s , string p , int n , int m)
{
	string str = p + "$" + s ;  n = str.size() ;

	int l = 0 , r = 0 ; vector<int> z(n) ;
    
	for(int i = 1 ; i < n ; i++)
	{
        if(i > r)
		    {
            l = r = i ;

            while(r < n && str[r - l] == str[r])  r++ ;

            z[i] = r - l ; r--;
        }

        else if(i + z[i - l] <= r)  z[i] = z[i - l] ;

        else
  		  {
            l = i ;
                
    			while(r < n && str[r - l] == str[r] ) r++ ;
                
    			z[i] = r - l ;  r-- ;
        }
  }   
  
  int cnt = 0 ; 
	for(int i = 0 ; i < z.size() ; i++)
	{
        if(z[i] = m) cnt++ ;
  }

    return cnt ;
}

// Time Complexity:  O(N + M)
// Space Complexity: O(N)
