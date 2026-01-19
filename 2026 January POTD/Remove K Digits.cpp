class Solution {
public:
string removeKdig(string &s, int k) {
        // code here
        int n=s.length();

        if(k>=n) return "0";

        stack<char>st;
        st.push(s[0]);

        int i=1;

        for(;i<n && k>0; i++){
            while(!st.empty() && k>0 && st.top()>s[i]){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }

        while(i<n){
            st.push(s[i]);
            i++;
        }

        while(!st.empty() && k){
            st.pop();
            k--;
        }

        string tmp="";

        while(!st.empty()){
            tmp+=st.top();
            st.pop();
        }

        reverse(tmp.begin(), tmp.end());

        string ans="";

        for(char &ch:tmp){
            if(ch=='0' && ans.empty()) continue;
            ans+=ch;
        }

        return ans.empty()?"0":ans;        
    }
};
