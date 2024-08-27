class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        
        vector<int>lft(n, 0), rgt(n, 0);
        
        stack<int>st;
        
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            if(!st.empty()) lft[i]=st.top();
            st.push(arr[i]);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            if(!st.empty()) rgt[i]=st.top();
            st.push(arr[i]);
        }
        
        int maxi=0;
        
        for(int i=0; i<n; i++){
            maxi=max(maxi, abs(lft[i]-rgt[i]));
        }
        
        return maxi;
    }
};
