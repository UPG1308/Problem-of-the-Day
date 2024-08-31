class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
        int n = arr.size();
        vector<int> left(n, 1e8), right(n, -1e8);
        // left[0] = arr[0];
        for(int i = 1; i < n; ++i) left[i] = min(left[i - 1], arr[i - 1]);
        
        // right[n - 1] = arr[n - 1]
        for(int i = n - 2; i >= 0; --i) right[i] = max(right[i + 1], arr[i + 1]);
        
        for(int i = 1; i < n - 1; ++i){
            if(arr[i] > left[i] and arr[i] < right[i]) return {left[i], arr[i], right[i]};
        }
        return {};
    }
};
