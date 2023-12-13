class Solution {
    long countStrings(int n) {
        // code here
        long dp[] = new long[n+1];
        dp[1] = 2;
        dp[0] = 1;
        int mod = (int)1e9+7;
        for(int i= 2; i<=n; i++) 
            dp[i] = (dp[i-1]+dp[i-2])%mod;
        return dp[n]%mod;
    }
}
