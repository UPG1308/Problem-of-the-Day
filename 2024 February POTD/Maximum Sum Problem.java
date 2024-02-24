class Solution
{
    int dp[];
    public int maxSum(int n) 
    { 
        dp = new int[n + 1];
        Arrays.fill(dp, -1);
        return maxsum(n);
    } 
    public int maxsum(int n){
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = Math.max(n, maxsum(n/2) + maxsum(n/3) + maxsum(n/4));
    }
}
