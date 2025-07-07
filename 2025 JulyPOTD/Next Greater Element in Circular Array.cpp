class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, -1);
        
        for(int i = 0; i < 2 * n; ++i){
            while(!st.empty() && arr[i%n] > arr[st.top()%n]) {
                ans[st.top()%n] = arr[i%n];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
