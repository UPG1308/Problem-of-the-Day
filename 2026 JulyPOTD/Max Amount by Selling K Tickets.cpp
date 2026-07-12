class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        // code here
        int MOD = 1e9 + 7;
        priority_queue<array<int, 2>> pq;
        for(auto it: arr){
            pq.push({it, min(k, it)});
        }
        int ans = 0;
        while(!pq.empty() && k){
            auto [price, cnt] = pq.top(); pq.pop();
            ans = (ans + price) % MOD;
            k--;
            if(cnt > 0) pq.push({price - 1, cnt - 1});
        }
        
        return ans;
    }
};
