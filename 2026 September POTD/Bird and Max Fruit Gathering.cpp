class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        // code here
        int n = arr.size();
        vector<int> pref(2 * n + 1);
        for(int i = 0; i < 2 * n; ++i) pref[i + 1] = pref[i] + arr[i % n];
        int ans = 0;
        for(int i = m; i <= 2 * n; ++i) ans = max(ans, pref[i] - pref[i - m]);
        return ans;
    }
};
