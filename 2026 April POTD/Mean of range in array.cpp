class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n = arr.size();
        vector<int> pref(n + 1), ans;
        
        for(int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + arr[i - 1];
        for(auto it: queries){
            int l = it[0], r = it[1];
            ans.push_back((pref[r + 1] - pref[l])/(r - l + 1));
        }
        return ans;
    }
};
