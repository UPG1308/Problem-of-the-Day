class Solution {
  public:
    int minSquares(int n) {
        // Code here
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;
        for(int i = 1; i * i <= n; ++i){
            for(int j = 0; j <= n; ++j){
                if(i * i + j <= n) dp[i * i + j] = min(dp[i * i + j], dp[j] + 1);
            }
        }
        
        return dp[n];
    }
};
