class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<int> row(n), col(n);
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(mat[i][j]){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        
        for(int i = 0; i < n; ++i){
            if(row[i] == 1 && col[i] == n) return i;
        }
        return -1;
    }
};
