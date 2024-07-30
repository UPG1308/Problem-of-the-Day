class Solution {
  public:
    bool isPathExist = false;
    bool boundaryCheck(int row, int col, int n){
        return row >= 0 and row < n and col >= 0 and col < n;
    }
    void backtrack(int row, int col, vector<vector<int>> &mat, string &path, vector<string> &ans){
        if(row == mat.size() - 1 and col == mat[0].size() - 1){
            ans.push_back(path);
            isPathExist = true;
            return;
        }
        mat[row][col] = 0;
        int delCol[] = {0, 0, -1, +1};
        int delRow[] = {-1, +1, 0, 0};
        string dir = "UDLR";
        for(int i = 0; i < 4; i++){
            int curRow = row + delRow[i];
            int curCol = col + delCol[i];
            if(boundaryCheck(curRow, curCol, mat.size()) and mat[curRow][curCol] == 1){
                path.push_back(dir[i]);
                backtrack(curRow, curCol, mat, path, ans);
                path.erase(path.size() - 1);
            }
        }
        mat[row][col] = 1;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string> ans, noPath;
        string s = "";
        noPath.push_back("-1");
        if((mat[0][0] == 0)) return noPath;
        backtrack(0, 0, mat, s, ans);
        return ans;
    }
};
