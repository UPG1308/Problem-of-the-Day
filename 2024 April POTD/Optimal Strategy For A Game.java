class solve
{
    //Function to find the maximum possible amount of money we can win.
    static long countMaximum(int n, int arr[])
    {
        // Your code here
        long[][] dp = new long[n][n];
        for(long[]e:dp){
            Arrays.fill(e,-1);
        }
        return helper(arr,dp,0,arr.length-1,0);
    }
    
    static long helper(int[] arr,long[][] dp,int l,int r,int p){
        if(l>r)
            return 0;
        if(dp[l][r]!=-1)
            return dp[l][r];
        long total = 0;
        long res = p == 1 ? Long.MAX_VALUE : Long.MIN_VALUE;
        total = arr[l];
        if(p==0){
            res = Math.max(res,total+helper(arr,dp,l+1,r,1));
        }
        else
            res = Math.min(res,helper(arr,dp,l+1,r,0));
        total = arr[r];
        if(p==0){
            res = Math.max(res,total+helper(arr,dp,l,r-1,1));
        }
        else
            res = Math.min(res,helper(arr,dp,l,r-1,0));
        return dp[l][r] = res;
    }
}
