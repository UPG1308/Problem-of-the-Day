class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        int count = 0;
        unordered_map<int, int> mp;
        for(int num: arr){
            count += mp[target - num];
            mp[num]++;
        }
        return count;
    }
};
