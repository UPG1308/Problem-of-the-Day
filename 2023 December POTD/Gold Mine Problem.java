
class Solution{
    static int maxGold(int n, int m, int M[][])
    {
        // code here
        
        int [][]dp = new int[n][m];
        for(int[] in: dp) Arrays.fill(in, -1);
        int max = 0;
        for(int i = 0; i < M.length; i++){
            max = Math.max(max, helper(i, 0, M, dp));
        }
        return max;
    }
    
    static int helper(int i, int j, int[][] mine, int[][] dp){
        if(i < 0 || i >= mine.length) return (int) -1e6;
        if(j == mine[0].length - 1) return mine[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int right = mine[i][j] + helper(i, j + 1, mine, dp);
        int UpDiag = mine[i][j] + helper(i - 1, j + 1, mine, dp);
        int downDiag = mine[i][j] + helper(i + 1, j + 1, mine, dp);
        
        return dp[i][j] = Math.max(right, Math.max(UpDiag, downDiag));
    }
}
