class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &q) {
        // code here
        int n = q.size();
        sort(arr.begin(), arr.end());
        vector<int> ans(n);
        
        for(int i = 0; i < n; ++i){
            int l = q[i][0], r = q[i][1];
            int lb = lower_bound(arr.begin(), arr.end(), l) - arr.begin();
            int ub = upper_bound(arr.begin(), arr.end(), r) - arr.begin();
            ans[i] = ub - lb;
        }
        return ans;
    }
};
