class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp = arr;
        int sum = arr[0];
        
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(arr[i] > arr[j]) dp[i] = max(dp[i], arr[i] + dp[j]);
                sum = max(sum, dp[i]);
            }
        }
        
        return sum;
    }
};
