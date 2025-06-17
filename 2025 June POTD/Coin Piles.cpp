class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        vector<long long> prefix(n + 1);
        for(int i = n - 1; i >= 0; --i) prefix[i] = prefix[i + 1] + arr[i];
        
        // for(int i = 0; i <= n; ++i) cout << prefix[i] << " \n"[i == n];
        
        long long preSum = 0, coins = prefix[0];
        for(int i = 0; i < n; ++i){
            int it = upper_bound(arr.begin() + i, arr.end(), arr[i] + k) - arr.begin();
            long long rightSum = 0;
            if(it < n){
                rightSum = prefix[it] - (n - it) * (arr[i] + k);
            }
            coins = min(coins, preSum + rightSum);
            preSum += arr[i];
        }
        
        return coins;
    }
};
