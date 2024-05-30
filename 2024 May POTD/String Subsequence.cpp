class Solution {
  public:
    int mod = 1e9 + 7;
    int helper(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp){
        if(ind2 == s2.length()) return 1;
        if(ind1 > s1.length()) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        int pick = 0, notPick = 0;
        notPick = helper(ind1 + 1, ind2, s1, s2, dp);
        if(s1[ind1] == s2[ind2]) pick = helper(ind1 + 1, ind2 + 1, s1, s2, dp);
        return dp[ind1][ind2] = (pick % mod + notPick % mod) % mod;
    }
  
    int countWays(string s1, string s2) {
        // code here
        int n1 = s1.length(), n2 = s2.length();
        vector<vector<int>> dp(n1 + 2, vector<int>(n2 + 2, -1));
        return helper(0, 0, s1, s2, dp);
    }
};
