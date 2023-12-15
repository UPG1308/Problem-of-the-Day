
class Solution
{
    public int nthPoint(int n)
{
        // Code here
        int MOD = (int)1e9 + 7;
        int[] dp = new int[n + 1];
        
        if(n == 0 || n == 1 || n == 2) {
            return n;
        }
        
        dp[1] = 1;
        dp[2] = 2;
        
        int i = 3;
        while(i <= n) {
            dp[i] = ((dp[i - 2] % MOD) + (dp[i - 1] % MOD)) % MOD;
            i++;
        }
        
        return dp[n];
}
}
