class Solution {
  public:
    int numOfWays(int n, int m) {
        // code here
        int count = 0;
        int row[] = {-2, -1, +1, +2, +2, +1, -1, -2};
        int col[] = {+1, +2, +2, +1, -1, -2, -2, -1};
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                int total = n * m - 1;
                for(int k = 0; k < 8; ++k){
                    int nrow = i + row[k];
                    int ncol = j + col[k];
                    total -= nrow >= 0 && nrow < n && ncol >= 0 && ncol < m;
                }
                count += total;
            }
        }
        
        return count;
    }
};
