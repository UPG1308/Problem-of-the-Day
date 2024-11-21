class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int n = prices.size(), profits = 0;
        for(int i = 1; i < n; ++i){
            int prof = prices[i] - prices[i - 1];
            profits += max(0, prof);
        }
        return profits;
    }
};
