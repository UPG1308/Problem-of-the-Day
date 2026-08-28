class Solution {
  public:
    int minCost(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 1e8));
        
        for(int i = 0; i < 3; ++i) dp[0][i] = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < 3; ++j){
                for(int k = 0; k < 3; ++k){
                    if(j == k) continue;
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][k] + mat[i][k]);
                }
            }
        }
        
        int ans = 1e8;
        for(int i = 0; i < 3; ++i) ans = min(ans, dp[n][i]);
        return ans;
    }
};
