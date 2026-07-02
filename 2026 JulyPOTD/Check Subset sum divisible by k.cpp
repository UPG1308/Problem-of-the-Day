class Solution {
  public:
    bool divisibleByK(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(k, -1));
        dp[0][0] = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < k; ++j){
                if(dp[i][j] != -1){
                    dp[i + 1][(j + arr[i]) % k] = max(dp[i + 1][(j + arr[i]) % k], dp[i][j] + 1);
                    dp[i + 1][j] = max(dp[i + 1][j] , dp[i][j]);
                }
            }
        }
        return dp[n][0] > 0;
    }
};
