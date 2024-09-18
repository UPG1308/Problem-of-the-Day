class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        for(char c: x){
            if(c == '(' or c == '{' or c == '[') st.push(c);
            else{
                if(c == ')'){
                    if(!st.empty() and st.top() == '(') st.pop();
                    else return false;
                }
                else if(c == '}'){
                    if(!st.empty() and st.top() == '{') st.pop();
                    else return false;
                }
                else{
                    if(!st.empty() and st.top() == '[') st.pop();
                    else return false;
                }
            }
        }
        return st.empty();
    }

};
