class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int up = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
        int lo = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
        return up - lo;
        
        
    }
};
