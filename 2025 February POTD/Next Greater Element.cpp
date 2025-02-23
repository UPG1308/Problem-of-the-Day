class Solution {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        // solving using stack
        stack<int> st;
        st.push(-1);
        int n=arr.size();
        vector<int> ans(n,-1);
        for(int i=n-1;i>=0;i--)
        {
            // int top = st.top();
            if(arr[i]<st.top())
            {
                ans[i]=st.top();
                st.push(arr[i]);
            }
            else
            {
                while(st.top()!=-1 && arr[i]>=st.top())
                {
                    st.pop();
                }
                ans[i]=st.top();
                st.push(arr[i]);
            }
        }
        return ans;
    }
};
