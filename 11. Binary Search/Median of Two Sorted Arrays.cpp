// LeetCode Link: https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// --------------------------------------------------------------------------------------

double median(vector<int>& a, vector<int>& b) 
{
	int n1 = a.size() ;  int n2 = b.size() ;

	if(n1 > n2)  return median(b , a)  ;

	int low = 0 ;  int high = n1 ;

	while(low <= high)
	{
		int cut1 = low + (high - low) / 2 ;
		int cut2 = (n1 + n2 + 1) / 2  - cut1 ;

		int l1 = cut1 == 0 ?  INT_MIN : a[cut1 - 1] ;
		int l2 = cut2 == 0 ?  INT_MIN : b[cut2 - 1] ;

		int r1 = cut1 == n1 ?  INT_MAX : a[cut1] ;
		int r2 = cut1 == n2 ?  INT_MAX : b[cut2] ;

		if(l1 <= r2  && l2 <= r1)
		{
			if((n1 + n2) % 2 == 0)
			{
				double v1 = max(l1 , l2) ;  double v2 = min(r1, r2) ;

				return (v1 + v2) / 2.0 ;
			}

			else  return max(l1 , l2) * 1.0 ;
		}

		else if (l1 > r2)  high = cut1 - 1 ;

		else low = cut1 + 1 ;
	}

	return 0.0 ;
}

// Time Complexity:  O(Log( min(n1, n2))) 
// Space Complexity: O(1)
