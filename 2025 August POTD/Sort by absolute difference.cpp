class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // code here
        int n = arr.size();
        vector<int> indices(n), ans(n);
        iota(indices.begin(), indices.end(), 0);
        
        sort(indices.begin(), indices.end(), [&](int a, int b){
            if(abs(arr[a] - x) == abs(arr[b] - x)) return a < b;
            else return abs(arr[a] - x) < abs(arr[b] - x);
            });
        
        for(int i = 0; i < n; ++i){
           ans[i] = arr[indices[i]];
        }
        
        for(int i = 0; i < n; ++i){
          arr[i] = ans[i];
        }
    }
};
