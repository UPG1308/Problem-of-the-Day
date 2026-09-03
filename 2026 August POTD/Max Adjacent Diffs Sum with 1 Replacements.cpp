class Solution {
  public:
    int maxDiffSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n == 1) return 0;
        vector<vector<int>> dp(2, vector<int>(n));
        
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < 2; ++j){
                int cur = j? arr[i]: 1;
                dp[j][i] = max(dp[0][i - 1] + abs(cur - 1), dp[1][i - 1] + abs(cur - arr[i - 1]));
            }
        }
        return max(dp[0][n - 1], dp[1][n - 1]);
    }
};
