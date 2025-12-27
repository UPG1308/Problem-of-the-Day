class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int n = mat.size();
        
        auto check = [&](int m){
            int cnt = 0;
            for(int i = 0; i < n; ++i){
                int ub = upper_bound(mat[i].begin(), mat[i].end(), m) - mat[i].begin();
                cnt += ub;
            }
            return cnt >= k;
        };
        
        int l = 0, r = 1e9;
        while(r - l > 1){
            int m = l + (r - l)/2;
            if(check(m)) r = m;
            else l = m;
        }
        
        return r;
    }
};
