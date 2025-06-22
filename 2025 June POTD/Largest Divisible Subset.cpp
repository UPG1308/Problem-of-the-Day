class Solution {
  public:
    
    int helper(int ind, int prev, vector<int> &arr, vector<vector<int>> &dp){
            
        if(ind == arr.size()) return 0;
        
        if(dp[ind][prev + 1] != -1) return dp[ind][prev + 1];
        
        int pick = 0, notpick = 0;
        notpick = helper(ind + 1, prev, arr, dp);
        
        if(prev == -1 || arr[ind] % arr[prev] == 0){
            pick = 1 + helper(ind + 1, ind, arr, dp);
        }
        
        return dp[ind][prev + 1] = max(pick, notpick);
    }
    
    vector<int> traceback(vector<vector<int>> &dp, vector<int> &arr) {
        int n = arr.size();
        vector<int> ans;
    
        int prev = -1;
        for (int ind = 0; ind < n; ++ind) {
            // pick condition: if including arr[ind] is valid and beneficial
            if (prev == -1 || arr[ind] % arr[prev] == 0) {
                int pick = 1 + (ind + 1 < n ? dp[ind + 1][ind + 1] : 0);
                int notpick = (ind + 1 < n ? dp[ind + 1][prev + 1] : 0);
    
                if (pick > notpick) {
                    ans.push_back(arr[ind]);
                    prev = ind;
                }
            }
        }

    return ans;
}

    
    vector<int> largestSubset(vector<int>& arr) {
        // Code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        int count = helper(0, -1, arr, dp);
        
        return traceback(dp, arr);
    }
};
