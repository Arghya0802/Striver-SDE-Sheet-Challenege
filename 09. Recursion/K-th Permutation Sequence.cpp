// LeetCode Link: https://leetcode.com/problems/permutation-sequence/description/
// -----------------------------------------------------------------------------

/* Approach [Typical Algorithmic question]
1. We need to return the K-th permutation from 1 to N, but as N can be equal to 9, we cannot generate all the possible permutations.
2. We need to use a particular algorithm to solve the question.
3. We first push all the numbers from 1 to N inside vector nums[] and calculate till (N - 1)! and store it inside the Fact variable. We decrement K by 1 as we follow 0-based indexing
4. The index of the current element of our K-th Permutation Sequence is K / Fact.
5.  To get the rest of the digits, we decrement K as K % Fact and decrement Fact as Fact /= nums.size() [we move to (N - 2)! and so on]
6. We break out of the loop, whenever our nums become empty or nums.size() equals 0.
*/

string kthPermutation(int n, int k) 
{
    k-- ;  // We are considering 0-based indexing 

    int fact = 1 ;

    vector<int> nums ;  

    for(int i = 1 ; i < n ; i++)
    {
        nums.push_back(i) ;  fact *= i ;
    }

    nums.push_back(n) ;   string ans = "" ;  

    while(true)
    {
        int ind = k / fact ; // This gives us the Index of the Current Element

        ans += to_string(nums[ind]) ;

        nums.erase(nums.begin() + ind) ; // We erase it from our nums[] vector

        if(nums.size() == 0) break ;

        k %= fact ;  fact /= nums.size() ;
    }

    return ans ;
}


// Time Complexity:  O(N ^ 2) [To iterate over all the elements once and delete the element after we have taken it]
// Space Complexity: O(N) [We have taken extra nums[] vector]
