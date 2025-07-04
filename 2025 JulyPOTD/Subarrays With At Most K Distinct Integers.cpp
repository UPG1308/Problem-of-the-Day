class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        
        int n = arr.size(), count = 0;
        map<int, int> mp;
        for(int begin = 0, end = 0; end < n; ++end){
            mp[arr[end]]++;
            while(mp.size() > k){
                mp[arr[begin]]--;
                if(mp[arr[begin]] == 0) mp.erase(arr[begin]);
                begin++;
            }
            count += end - begin + 1;
        }
        return count;
    }
};
