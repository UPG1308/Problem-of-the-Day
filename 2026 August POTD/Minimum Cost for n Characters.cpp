class Solution {
  public:
    int minCost(int n, int i, int d, int c) {
        // code here
        int MAX = 1e9;
        vector<int> dp(2 * n + 3, MAX);
        dp[0] = 0;
        for(int j = 0; j < 2 * n;){
            dp[j + 1] = min(dp[j + 1], dp[j] + i);
            if(j <= n) dp[2 * j] = min(dp[2 * j], dp[j] + c);
            if(j && dp[j - 1] > dp[j] + d) {
                dp[j - 1] = dp[j] + d;
                j -= 2;
            }
            j++;
        }
        return dp[n];
    }
};
