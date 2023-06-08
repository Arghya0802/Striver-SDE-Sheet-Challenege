// LeetCode Link:  https://leetcode.com/problems/majority-element-ii/description/
// ---------------------------------------------------------------------------------

/* Approach [Bayer Moore Majority Voting Algo extension]
1. Using maths, we can easily find that we only have at most two elements whose frequency is more than [> n / 3].
2. The approach remains the same. But we have to ensure that we don't allocate the same element to majorA and majorB.
3. Similarly, we need to cross-check the frequencies of majorA and majorB before putting them inside our final ans[] vector.
4. The core idea remains exactly the same- we find the majority element by the cancellation technique.
*/

#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size() ;
    
    vector<int> ans ;

    int cntA = 0 , cntB = 0 ;
    int majorA = INT_MAX , majorB = INT_MAX ;

    for(int i = 0 ; i < n ; i++)
    {
        if(cntA == 0 && majorB != arr[i])  majorA = arr[i] ;

        else if(cntB == 0 && majorA != arr[i])  majorB = arr[i] ;

        if(arr[i] == majorA)  cntA++ ;

        else if(arr[i] == majorB)  cntB++ ;

        else
        {
            cntA-- ; cntB-- ;
        }
    }
    
    int freqA = 0 ; int freqB = 0 ;

    for(int i = 0 ; i < n ; i++)
    {
        if(majorA == arr[i])  freqA++ ;

        if(majorB == arr[i])  freqB++ ;
    }

    if(freqA * 3 > n)  ans.push_back(majorA) ;

    if(freqB * 3 > n)  ans.push_back(majorB) ;

    return ans ;
}

// Time Complexity:   O(N)
// Space Complexity:  O(1)
