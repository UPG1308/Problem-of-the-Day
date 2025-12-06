class Solution {
  public:
  
    int maximumAmount(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        for (int g = 0; g < n; g++) {  // gap
            for (int i = 0, j = g; j < n; i++, j++) {
                if (g == 0)
                    dp[i][j] = arr[i];
                else if (g == 1)
                    dp[i][j] = max(arr[i], arr[j]);
                else {
                    long long val1 = arr[i] + min(dp[i+2][j], dp[i+1][j-1]);
                    long long val2 = arr[j] + min(dp[i+1][j-1], dp[i][j-2]);
                    dp[i][j] = max(val1, val2);
                }
            }
        }
    
        return dp[0][n-1];
    }
};
