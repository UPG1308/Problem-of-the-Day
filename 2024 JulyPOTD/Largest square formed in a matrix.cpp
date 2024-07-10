class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1){
                    dp[i + 1][j + 1] = min(dp[i][j + 1], min(dp[i + 1][j], dp[i][j])) + 1;
                    ans = max(ans, dp[i + 1][j + 1]);
                }
            }
        }
        return ans;
    }
};
