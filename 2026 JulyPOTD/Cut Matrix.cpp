#include <vector>

using namespace std;

class Solution {
public:
    int findWays(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int MOD = 1e9 + 7;

        // 1. Precalculate 1s in the subgrid from (i, j) to the bottom-right corner
        vector<vector<int>> ones(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                ones[i][j] = matrix[i][j] + ones[i + 1][j] + ones[i][j + 1] - ones[i + 1][j + 1];
            }
        }

        // Early exit: if there aren't enough 1s in the whole matrix to give each piece at least one '1'
        if (ones[0][0] < k) return 0;

        // 2. Precompute the very first valid row (next_r) and column (next_c) we can cut at.
        // This completely eliminates the O(n + m) loops from the DP transitions.
        vector<vector<int>> next_r(n + 1, vector<int>(m + 1, n));
        vector<vector<int>> next_c(n + 1, vector<int>(m + 1, m));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                // If the current row has a '1', the next valid cut is immediately below (i + 1).
                // Otherwise, inherit the next valid cut from the row below.
                next_r[i][j] = (ones[i][j] > ones[i + 1][j]) ? (i + 1) : next_r[i + 1][j];
                next_c[i][j] = (ones[i][j] > ones[i][j + 1]) ? (j + 1) : next_c[i][j + 1];
            }
        }

        vector<vector<int>> prev_dp(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        // Base case: If we only need 1 piece (k=1), 
        // the subgrid is valid if it contains at least one '1'.
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                prev_dp[i][j] = (ones[i][j] > 0) ? 1 : 0;
            }
        }

        if (k == 1) return prev_dp[0][0];

        vector<vector<int>> row_sum(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> col_sum(n + 1, vector<int>(m + 1, 0));

        // 3. Process exactly from 2 pieces up to k pieces
        for (int step = 2; step <= k; ++step) {
            
            // Maintain Suffix Sums of the previous state to allow O(1) lookups
            for (int i = n - 1; i >= 0; --i) {
                for (int j = m - 1; j >= 0; --j) {
                    row_sum[i][j] = (prev_dp[i][j] + row_sum[i + 1][j]) % MOD;
                    col_sum[i][j] = (prev_dp[i][j] + col_sum[i][j + 1]) % MOD;
                }
            }

            // Fill current DP state for the current number of pieces
            for (int i = n - 1; i >= 0; --i) {
                for (int j = m - 1; j >= 0; --j) {
                    // If the current subgrid is empty of 1s, it's impossible.
                    if (ones[i][j] == 0) {
                        dp[i][j] = 0;
                        continue;
                    }

                    long long ways = 0;
                    
                    // O(1) Horizontal cut sum
                    int nr = next_r[i][j];
                    if (nr < n) {
                        ways = (ways + row_sum[nr][j]) % MOD;
                    }

                    // O(1) Vertical cut sum
                    int nc = next_c[i][j];
                    if (nc < m) {
                        ways = (ways + col_sum[i][nc]) % MOD;
                    }

                    dp[i][j] = ways;
                }
            }
            // Move current state to previous for the next iteration
            prev_dp = dp;
        }

        return prev_dp[0][0];
    }
};
