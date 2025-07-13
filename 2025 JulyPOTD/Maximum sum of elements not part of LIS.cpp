class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<long long> sum(n, 1e9);
        int maxlen = 1;
        for(int i = 0; i < n; ++i){
            int len = 0;
            for(int j = 0; j < i; ++j){
                if(arr[j] < arr[i]) len = max(len, dp[j]);
            }
            long long cursum = 1e9;
            for(int j = 0; j < i; ++j){
                if(arr[j] < arr[i] && dp[j] == len) cursum = min(cursum, sum[j]);
            }
            sum[i] = (cursum ==1e9? 0: cursum) + arr[i];
            dp[i] = len + 1;
            maxlen = max(maxlen, dp[i]);
        }
        
        long long ans = 1e9;
        for(int i = 0; i < n; ++i){
            if(dp[i] == maxlen) ans = min(ans, sum[i]);
        }
        return accumulate(arr.begin(), arr.end(), 0) - ans;
    }
};
