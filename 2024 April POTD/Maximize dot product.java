class Solution
{
	public int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		// Your code goes here
		int zeros = n - m;
		int dp[][] = new int[n + 1][zeros + 1];
		for(int ind2 = m - 1; ind2 >= 0; ind2--){
		    for(int zeroRem = 0; zeroRem <= zeros; zeroRem++){
		        int considerZero = 0;
		        int ind1 = ind2 + (zeros - zeroRem);
		        if(ind1 == n) continue;
        	    if(zeroRem > 0) considerZero = dp[ind2][zeroRem - 1];
        	    int notConsiderZero = a[ind1] * b[ind2] + dp[ind2 + 1][zeroRem];
        	    dp[ind2][zeroRem] = Math.max(considerZero, notConsiderZero);
		    }
		}
		return dp[0][zeros];
// 		return solve(0, zeros, a, b, dp, zeros);
	} 
	public int solve(int ind2, int zeroRem, int[] a, int[] b, int[][] dp, int zeros){
	    int ind1 = ind2 + (zeros - zeroRem);
	    if(ind1 == a.length || ind2 == b.length) return 0;
	    if(dp[ind2][zeroRem] != -1) return dp[ind2][zeroRem];
	    
	    int considerZero = 0;
	    if(zeroRem > 0) considerZero = solve(ind2, zeroRem - 1, a, b, dp, zeros);
	    int notConsiderZero = a[ind1] * b[ind2] + solve(ind2 + 1, zeroRem, a, b, dp, zeros);
	    return dp[ind2][zeroRem] = Math.max(considerZero, notConsiderZero);
	}
}
