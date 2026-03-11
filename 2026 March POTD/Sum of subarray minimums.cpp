class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n = arr.size();
        stack<int> st;
        st.push(-1);
        int ans = 0;
        
        for(int i = 0; i <= n; ++i){
            while(st.size() > 1 && (i == n || arr[i] <= arr[st.top()])){
                int top = st.top(); st.pop();
                int len = (i - top) * (top - st.top());
                ans += len * arr[top];
            }
            st.push(i);
        }
        
        return ans;
    }
};
