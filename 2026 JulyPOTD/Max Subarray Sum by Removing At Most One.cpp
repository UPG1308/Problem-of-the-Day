class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        // code here
        int n = arr.size(), ans = -1e9;
        vector<int> pref(n), suff(n);
        pref[0] = arr[0], suff[n - 1] = arr[n - 1];
        ans = max({ans, pref[0], suff[n - 1]});
        for(int i = 1; i < n; ++i){
            pref[i] = max(arr[i], arr[i] + pref[i - 1]);
            ans = max(ans, pref[i]);
        }
        
        for(int i = n - 2; i >= 0; --i){
            suff[i] = max(arr[i], suff[i + 1] + arr[i]);
            ans = max(ans, suff[i]);
        }
        for(int i = 1; i < n - 1; ++i){
            ans = max(ans, pref[i - 1] + suff[i + 1]);
        }
        return ans;
    }
};
