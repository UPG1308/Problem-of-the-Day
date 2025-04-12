class Solution {
  public:
    
     bool boundaryCheck(int r, int c, int n, int m){
        return r >= 0 && r < n && c >= 0 && c < m;
    }
    
    void dfs(int row, int col, int newColor, vector<vector<int>>& image, int oldColor, int n, int m){
        image[row][col] = newColor;
        int delRow[] = {+1, 0, -1, 0};
        int delCol[] = {0, -1, 0, +1};
        for(int i = 0; i < 4; ++i){
            int r = row + delRow[i];
            int c = col + delCol[i];
            if(boundaryCheck(r, c, n, m) && image[r][c] == oldColor) dfs(r, c, newColor, image, oldColor, n, m);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int n = image.size(), m = image[0].size();
        int oldColor = image[sr][sc];
        if(oldColor == newColor) return image;
        dfs(sr, sc, newColor, image, oldColor, n, m);
        return image;
    }
};
