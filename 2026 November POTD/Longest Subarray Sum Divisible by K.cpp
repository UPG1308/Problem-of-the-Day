class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> mp;
        mp[0] = -1;
        int n = arr.size(), pref = 0, ans = 0;
        for(int i = 0; i < n; ++i){
            pref += arr[i];
            int rem = ((pref % k) + k) % k;
            if(mp.count(rem)){
                ans = max(ans, i - mp[rem]);
            } else {
                mp[rem] = i;
            }
        }
        return ans;
    }
};
