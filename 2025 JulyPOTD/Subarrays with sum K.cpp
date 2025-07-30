class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        int n = arr.size(), sum = 0, count = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int num: arr){
            sum += num;
            count += mp[sum - k];
            mp[sum]++;
        }
        return count;
    }
};
