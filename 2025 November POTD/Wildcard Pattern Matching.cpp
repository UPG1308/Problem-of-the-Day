class Solution {
  public:
    bool wildCard(string &txt, string &pat) {
        // code here
        int n = pat.size(), m = txt.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        
        dp[0][0] = 1;
        
        for(int i = 0; i < n; ++i){
            if(pat[i] == '*') dp[i + 1][0] |= dp[i][0];
            else break;
        }
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(pat[i] == txt[j] || pat[i] == '?' || pat[i] == '*'){
                    dp[i + 1][j + 1] = dp[i][j];
                }
                if(pat[i] == '*') dp[i + 1][j + 1] = dp[i + 1][j] || dp[i][j + 1];
            }
        }
        
        return dp[n][m];
    }
};
