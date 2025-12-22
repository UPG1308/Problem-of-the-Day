// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n = arr.size(), ans = 0, idx = -1;
        for(int i = 0; i < n; ++i){
            int cnt = arr[i].size() - (upper_bound(arr[i].begin(), arr[i].end(), 0) - arr[i].begin());
            if(ans < cnt) ans = cnt, idx = i;
        }
        return idx;
    }
};
