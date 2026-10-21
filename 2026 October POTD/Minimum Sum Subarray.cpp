class Solution {
  public:
    int minSubarraySum(vector<int> &arr) {
        // code here
        int mn = arr[0], sum = arr[0];
        int n = arr.size();
        for(int i = 1; i < n; ++i){
            sum = min(arr[i], sum + arr[i]);
            mn = min(mn, sum);
        }
        return mn;
    }
};
