class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int helper(int ind, int x, int y, int z){
        if(ind == x or ind == y or ind == z) return 1;
        if(ind < 0) return -1e5;
        int count = 0;
        count = max(count, 1 + helper(ind - x, x, y, z));
        count = max(count, 1 + helper(ind - y, x, y, z));
        count = max(count, 1 + helper(ind - z, x, y, z));
        return count;
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> dp(1e4 + 2, 0);
        dp[x] = 1, dp[y] = 1, dp[z] = 1;
        for(int i = 1; i <= n; i++){
            if(i - x >= 0 and dp[i - x] > 0) dp[i] = max(dp[i], 1 + dp[i - x]);
            if(i - y >= 0 and dp[i - y] > 0) dp[i] = max(dp[i], 1 + dp[i - y]);
            if(i - z >= 0 and dp[i - z] > 0) dp[i] = max(dp[i], 1 + dp[i - z]);
        }
        return dp[n];
    }
};
