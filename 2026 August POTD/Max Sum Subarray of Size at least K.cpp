class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(0);
        int ans = -1e9;
        vector<int> pref(n + 1);
        
        for(int i = 0; i < n; ++i){
            pref[i + 1]  = pref[i] + arr[i];
        }
        for(int i = k; i <= n; ++i){
            pq.push(pref[i - k]);
            ans = max(ans, pref[i] - pq.top());
        }
        return ans;
    }
};
