class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n);
        dp[0] = arr[0];
        if(n > 0) dp[1] = max(dp[0], arr[1]);
        
        for(int i = 2; i < n; ++i){
            dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n - 1];
    }
};
