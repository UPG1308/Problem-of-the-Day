// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        vector<int> row(n, -1), col(m, -1);
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(mat[i][j] == 0){
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }
        
        for(int i = 0; i < n; ++i){
            if(row[i] == 0){
                for(int j = 0; j < m; ++j) mat[i][j] = 0;
            }
        }
        
        for(int j = 0; j < m; ++j){
            if(col[j] == 0){
                for(int i = 0; i < n; ++i) mat[i][j] = 0;
            }
        }
    }
};
