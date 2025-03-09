class Solution {
  public:
    int countPS(string &s) {
        // code here
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, 0));
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 1) {
                    dp[i][j] = 1;
                }else if (i == 2 and s[j] == s[j + i - 1]) {
                    dp[i][j] = 1;
                    ans++;
                }else if (i >= 3 and s[j] == s[j + i - 1] and dp[i - 2][j + 1]) {
                    dp[i][j] = 1;
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
