class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int n = prices.size(), mn = prices[0], mx = 0;
        for(int i = 1; i < n; ++i){
            mn = min(prices[i], mn);
            mx = max(prices[i] - mn, mx);
        }
        return mx;
    }
};
