class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int ans = arr[n - 1] - arr[0];
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;
        for(int i = 1; i < n; ++i){
            int mn = min(smallest, arr[i] - k);
            int mx = max(largest, arr[i - 1] + k);
            if(mn < 0) continue;
            ans = min(ans, mx - mn);
        }
        return ans;
    }
};
