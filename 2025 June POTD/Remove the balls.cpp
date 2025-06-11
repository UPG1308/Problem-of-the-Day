class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        int n = color.size();
        stack<pair<int, int>> st;
        
        for(int i = 0; i < n; ++i){
            if(!st.empty() && st.top().first == color[i] && st.top().second == radius[i]) st.pop();
            else st.push({color[i], radius[i]});
        }
        return st.size();
    }
};
