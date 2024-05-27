class Solution {
    public static int longestSubseq(int n, int[] a) {
        // code here
        int dp[][] = new int[n + 2][n + 3];
        // for(int arr[]: dp)Arrays.fill(arr, -1);
        for(int ind = n - 1; ind >= 0; ind--){
            for(int lastInd = n - 1; lastInd >= 0; lastInd--){
                int take = 0, notTake = 0;
                notTake = dp[ind + 1][lastInd];
                if(lastInd == 0 || Math.abs(a[ind] - a[lastInd - 1]) == 1) take = 1 + dp[ind + 1][ind + 1];
                dp[ind][lastInd] = Math.max(take, notTake);
            }
        }
        return dp[0][0];
    }
    public static int helper(int ind, int lastInd, int n, int[] a, int[][] dp){
        if(ind == n) return 0;
        if(dp[ind][lastInd] != -1) return dp[ind][lastInd];
        int take = 0, notTake = 0;
        notTake = helper(ind + 1, lastInd, n, a, dp);
        if(lastInd == 0 || Math.abs(a[ind] - a[lastInd - 1]) == 1) take = 1 + helper(ind + 1, ind + 1, n, a, dp);
        return dp[ind][lastInd] = Math.max(take, notTake);
    }
}
