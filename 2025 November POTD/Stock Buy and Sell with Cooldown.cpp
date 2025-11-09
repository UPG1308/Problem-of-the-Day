class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        // code here
        int n = prices.size();
        vector<vector<long long>>dp(n+2, vector<long long>(2, 0));
            dp[n][0]=dp[n][1]=0;
            
            for(int i=n-1; i>=0; i--){
                for(int b=0; b<=1; b++){
                    long long profit;
                    if(b){
                        profit=max((-prices[i]+dp[i+1][0]), dp[i+1][1]);
                    }else{
                        profit=max((prices[i]+dp[i+2][1]), dp[i+1][0]);
                    }
                    dp[i][b]=profit;
                }
            }
            long long ans=dp[0][1];
            return ans;
    }
};
