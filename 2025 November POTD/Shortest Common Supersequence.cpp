class Solution {
  public:
    int lcs(string &s1, string &s2){
        int n1 = s1.size(), n2 = s2.size();
        
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        for(int i = 0; i < n1; ++i){
            for(int j = 0; j < n2; ++j){
                if(s1[i] == s2[j]) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], 1 + dp[i][j]);
                else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp[n1][n2];
    }
    int minSuperSeq(string &s1, string &s2) {
        // code here
        return s1.size() + s2.size() - lcs(s1, s2);
    }
};
