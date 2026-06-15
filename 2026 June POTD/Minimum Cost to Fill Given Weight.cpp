class Solution {
  public:
    int minimumCost(vector<int> &cost, int w) {
        // code here
        int n = cost.size();
        vector<int> dp(w + 2, INT_MAX);
        dp[0] = 0;
        
        for(int c = 0; c < n; ++c){
            for(int i = 0; i <= w; ++i){
                if(dp[i] == INT_MAX || (i + c + 1) > w) continue;
                dp[i + c + 1] = min(dp[i + c + 1], dp[i] + cost[c]);
            }
        }
        
        return dp[w] == INT_MAX? -1: dp[w];
    }
};
