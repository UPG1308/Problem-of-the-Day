class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        for(int j = wt[0]; j <= W; ++j) dp[0][j] = val[0];
        for(int i = 1; i < n; ++i){
            for(int j = 0; j <= W; ++j){
                dp[i][j] = max(((j - wt[i] >= 0)? (val[i] + dp[i - 1][j - wt[i]]):0), dp[i - 1][j]);
            }
        }
        return dp[n - 1][W];
    }
};