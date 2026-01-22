class Solution {
  public:
    int subarrayRanges(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> st;
        st.push_back(-1);
        
        long long ans = 0;
        
        for(int i = 0; i <= n; ++i){
            while(st.size() > 1 && (i == n || arr[st.back()] <= arr[i])) {
                int top = st.back();
                st.pop_back();
                long long len = (i - top) * (top - st.back());
                ans += len * arr[top];
            }
            st.push_back(i);
        }
        st.clear();
        st.push_back(-1);
        
        for(int i = 0; i <= n; ++i){
            while(st.size() > 1 && (i == n || arr[st.back()] >= arr[i])){
                int top = st.back();
                st.pop_back();
                long long len = (i - top) * (top - st.back());
                ans -= len * arr[top];
            }
            st.push_back(i);
        }
        
        return ans;
    }
};
