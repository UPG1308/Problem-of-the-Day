class Solution {
  public:
    int largestArea(int n, int m, vector<vector<int>> &arr) {
        // code here
        vector<int> row(n + 1), col(m + 1);
        for(auto it: arr){
            int r = it[0], c = it[1];
            row[r] = 1, col[c] = 1;
        }
        int maxRowLen = 0, rowLen = 0, maxColLen = 0, colLen = 0;
        for(int i = 1; i <= n; ++i){
            if(row[i] == 1) rowLen = 0;
            else rowLen++;
            maxRowLen = max(maxRowLen, rowLen);
        }
        
        for(int i = 1; i <= m; ++i){
            if(col[i] == 1) colLen = 0;
            else colLen++;
            maxColLen = max(maxColLen, colLen);
        }
        return maxRowLen * maxColLen;
    }
};
