// LeetCode Link:  https://leetcode.com/problems/valid-parentheses/
// --------------------------------------------------------------

bool isOpening(char ch)
{
    if(ch == '(' || ch == '[' || ch == '{')  return true ;
    
    return false ;
}

bool isValidParenthesis(string &expression)
{
    int n = expression.size() ;

    stack<char> st ;

    for(int i = 0 ; i < n ; i++)
    {
        char ch = expression[i] ;

        if(isOpening(ch) )  st.push(ch) ;

        else
        {
            if(st.empty() )  return false ;

            else if(ch == ')' && st.top() != '(')  return false ;

            else if(ch == ']' && st.top() != '[')  return false ;

            else if(ch == '}' && st.top() != '{')  return false ;

            else st.pop() ;
        }
    }

    return st.empty() ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N) [ Using an external Stack ]
