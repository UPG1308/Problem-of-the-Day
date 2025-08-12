class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        int n = prices.size();
        sort(prices.begin(),prices.end());
        int items = (n + k) / (k + 1);
        int mi = 0, ma = 0;
        for(int i = 0; i < items; ++i){
          mi += prices[i];
          ma += prices[n - i - 1];
          }
        return {mi, ma};
    }
};
