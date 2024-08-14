class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        int n1 = str1.size(), n2 = str2.size(), maxlen = 0;
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                if(str1[i] == str2[j]) maxlen = max(maxlen, dp[i + 1][j + 1] = 1 + dp[i][j]);
            }
        }
        return maxlen;
    }
};
