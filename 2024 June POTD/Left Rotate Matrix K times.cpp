class Solution {
  public:
    auto rotateMatrix(int k, vector<int>& mat, int m){
        vector<int> ans(m, 0);
        for(int i = 0; i < m; i++) ans[i] = mat[(i + k%m)%m];
        return ans;
    }
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            ans[i] = rotateMatrix(k, mat[i], m);
        }
        return ans;
    }
};
