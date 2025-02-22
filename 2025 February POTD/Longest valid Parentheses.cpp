class Solution {
  public:
    int maxLength(string& s) {
        // code here
        int n = s.size(), value = 0;
        vector<int> dp(n);
        for(int i = 1; i < n; ++i){
            if(s[i] == ')'){
                if(i - 1 >= 0 && s[i - 1] == '(') dp[i] = 2 + (i - 2 >= 0? dp[i - 2]: 0);
                else {
                    if(i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') dp[i] = 2 + dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0);
                }
            }
            value = max(value, dp[i]);
        }
        return value;
    }
};
