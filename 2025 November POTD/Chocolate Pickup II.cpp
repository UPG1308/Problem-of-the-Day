class Solution {
  public:
    
    int n;
    vector<vector<int>> mat;
    int dp[70][70][70];  // since n ≤ 70 usually, adjust if larger
    
    int solve(int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2;  // since r1+c1 == r2+c2
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n ||
            mat[r1][c1] == -1 || mat[r2][c2] == -1)
            return INT_MIN;
    
        if (r1 == n - 1 && c1 == n - 1)
            return mat[r1][c1];  // both reached end
    
        int &res = dp[r1][c1][r2];
        if (res != -1) return res;
    
        int choco = mat[r1][c1];
        if (r1 != r2 || c1 != c2)
            choco += mat[r2][c2];
    
        int best = max({
            solve(r1 + 1, c1, r2 + 1),  // both down
            solve(r1, c1 + 1, r2),      // both right
            solve(r1 + 1, c1, r2),      // r1 down, r2 right
            solve(r1, c1 + 1, r2 + 1)   // r1 right, r2 down
        });
    
        res = (best == INT_MIN) ? INT_MIN : choco + best;
        return res;
    }

    int maxChocolates(vector<vector<int>>& grid) {
        mat = grid;
        n = grid.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0, 0);
        return max(0, ans);
    }
  
    int chocolatePickup(vector<vector<int>> &mat) {
        // code here
        return maxChocolates(mat);
    }
};
