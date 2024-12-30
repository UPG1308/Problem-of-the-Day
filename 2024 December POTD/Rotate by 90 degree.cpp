class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]);
        }
        
        for(int j = 0; j < n; ++j){
            for(int i = 0; i < n/2; ++i) swap(mat[i][j], mat[n - i - 1][j]);
        }
    }
};