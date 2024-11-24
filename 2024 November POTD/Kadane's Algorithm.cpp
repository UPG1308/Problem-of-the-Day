class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        int n = arr.size(), maxsum = 0;
        vector<int> dp(n, 0);
        dp[0] = arr[0];
        for(int i = 1; i < n; ++i){
            dp[i] = max(dp[i - 1] + arr[i], arr[i]);
            maxsum = max(maxsum, dp[i]);
        }
        return maxsum;
    }
};
