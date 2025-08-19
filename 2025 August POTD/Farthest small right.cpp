class Solution {
private:
    int solve(int i, int n, vector<int> &arr, stack<int> st)
    {
        int idx=-1;
        
        while(!st.empty() && arr[st.top()]<arr[i]) {
            idx=st.top();
            st.pop();
        }
        
        return idx;
    }
    
public:
    vector<int> farMin(vector<int> &arr) 
    {
        int n=arr.size();
        vector<int> ans(n,-1);
        stack<int> st;              // monotonic stack - indices 
        
        for(int i=n-1; i>=0; i--) {
            int curr=arr[i];
            int element=solve(i,n,arr,st);
            ans[i]=element;
            
            if(st.empty() || arr[st.top()]>curr)    st.push(i);
        }
        
        return ans;
    }
};
