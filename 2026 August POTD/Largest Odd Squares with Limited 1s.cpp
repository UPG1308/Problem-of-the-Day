class Solution {
  public:
    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries,
                              int k) {
        // code here
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> pref(n + 1, vector<int>(m + 1));
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                pref[i][j] = mat[i - 1][j - 1] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            }
        }
        
        auto findOdd = [&](int r, int c, int l){
            if(r + l > n || c + l  > m || r - l - 1 < 0 || c - l - 1 < 0) return -1;
            int sum = pref[r + l][c + l] - pref[r - l - 1][c + l] - pref[r + l][c - l - 1] + pref[r - l - 1][c - l - 1];
            return (sum > k)? -1: sum;
        };
        
        vector<int> ans(queries.size(), -1);
        for(int i = 0; i < queries.size(); ++i){
            int l = 0;
            int r = queries[i][0], c = queries[i][1];
            while(true){
                int sum = findOdd(r + 1, c + 1, l);
                if(sum == -1) break;
                ans[i] = 2 * l + 1;
                l++;
            }
        }
        return ans;
    }
};
