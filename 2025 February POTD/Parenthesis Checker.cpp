class Solution {
  public:
    bool isleft(char lhs)
    {
        return lhs == '[' || lhs == '{' || lhs == '(';
    }
    
    bool isBalanced(string& s) {
        stack<char> st{};
        for(auto& i : s)
        {
            if ( isleft(i) )
                st.push(i);
            else if( st.empty())
                return false;
            else
            {
                if( i == ')')
                {
                    if( st.top() != '(')
                        return false;
                }
                else if( i == ']')
                 {
                     if( st.top() != '[')
                        return false;
                 }
                else if( i == '}')
                 {
                     if( st.top() != '{')
                        return false;
                 }
                st.pop();
            }
        }
        return st.empty();
    }
};
