class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        int delRow[] = {+1, 0, -1, 0};
        int delCol[] = {0, -1, 0, +1};
        
        auto boundaryCheck = [&](int r, int c){
            return r >= 0 && r < n && c >= 0 && c < m;
        };
        
        int mx = -1e9;
        vector<int> ans(2);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                int good = 1;
                for(int k = 0; k < 4; ++k){
                    int r = i + delRow[k];
                    int c = j + delCol[k];
                    if(boundaryCheck(r, c)){
                        if(mat[r][c] > mat[i][j]){
                            good = 0;
                            break;
                        }
                    }
                }
                if(good && mat[i][j] > mx){
                    mx = mat[i][j];
                    ans = {i, j};
                }
            }
        }
        
        return ans;
    }
};
