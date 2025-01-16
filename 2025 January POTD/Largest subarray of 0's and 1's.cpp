class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        unordered_map<int,int> mp;
        int n = arr.size(), pref = 0, len = 0;
        mp[0] = -1;
        
        for(int i = 0; i < n; ++i){
            pref += (arr[i] == 1)?1:-1;
            if(mp.find(pref) != mp.end()) len = max(len, i - mp[pref]);
            else mp[pref] = i;
        }
        return len;
    }
};
