class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        // Code here
        int n = arr.size(), ans = 0;
        sort(arr.begin(), arr.end());
        int prev = arr[0];
        for(int i = 1; i < n; ++i){
            if(arr[i] > prev) prev = arr[i];
            else {
                int diff = abs(prev - arr[i]) + 1;
                ans += diff; 
                prev = arr[i] + diff;
            }
        }
        return ans;
    }
};
