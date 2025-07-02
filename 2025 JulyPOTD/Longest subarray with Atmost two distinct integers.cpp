class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size(), ans = 0;
        map<int, int> mp;
        
        for(int begin = 0, end = 0; end < n; ++end){
            mp[arr[end]]++;
            while(begin <= end && mp.size() > 2){
                mp[arr[begin]]--;
                if(mp[arr[begin]] == 0) mp.erase(arr[begin]);
                begin++;
            }
            
            ans = max(ans, end - begin + 1);
        }
        return ans;
    }
};
