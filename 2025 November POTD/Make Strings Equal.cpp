class Solution {
  public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {
        // code here
        
        if(s.size() != t.size()) return -1;
        
        vector<vector<int>> dp(26, vector<int>(26, 1e9));
        for(int i = 0; i < transform.size(); ++i){
            dp[transform[i][0] - 'a'][transform[i][1] - 'a'] = min(dp[transform[i][0] - 'a'][transform[i][1] - 'a'], cost[i]);
        }
        for(int i = 0; i < 26; ++i) dp[i][i] = 0;
        
        for(int k = 0; k < 26; ++k){
            for(int i = 0; i < 26; ++i){
                for(int j = 0; j < 26; ++j){
                    if(dp[i][k] >= 1e9 || dp[k][j] >= 1e9) continue;
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        
        int total = 0;
        for(int i = 0; i < s.size(); ++i){
            int a = s[i] - 'a', b = t[i] - 'a';
            int best = 1e9;
            for(int c = 0; c < 26; ++c){
                if(dp[a][c] < 1e9 && dp[b][c] < 1e9) { 
                    best = min(best, dp[a][c] + dp[b][c]);
                }
            }
            if(best == 1e9) return -1;
            total += best;
        }
        
        return total;
    }
};
