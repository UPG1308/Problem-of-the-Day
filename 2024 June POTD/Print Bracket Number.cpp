class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        // Your code goes here
        vector<int> ans;
        stack<pair<char,int>> st;
        int cnt=0;
        for(char ch:str){
            if(ch=='('){
                st.push({ch,++cnt});
                ans.push_back(cnt);
            }
            else if(ch==')'){
                ans.push_back(st.top().second);
                st.pop();
            }
        }
        return ans;
    }
};
