class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        // code here
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<int>> pref(n + 1, vector<int>(m + 1));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                pref[i + 1][j + 1] = mat[i][j] + pref[i + 1][j] + pref[i][j + 1] - pref[i][j];
            }
        }
        
        int q = queries.size();
        vector<int> ans(q);
        
        for(int i = 0; i < q; ++i){
            int r1 = queries[i][0], c1 = queries[i][1], r2 = queries[i][2], c2 = queries[i][3];
            ans[i] = pref[r2 + 1][c2 + 1] - pref[r2 + 1][c1] - pref[r1][c2 + 1] + pref[r1][c1];
        }
        
        return ans;
    }
};
