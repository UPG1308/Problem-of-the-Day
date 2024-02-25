class Geeks {
    //Leetcode Coin change II
    public long count(int amount) {
        int[] coins={3,5,10};
        long [] dp=new long[amount+1];
        dp[0]=1;
        
        for(int i=0;i<coins.length;i++){
            for(int j=coins[i];j<dp.length;j++){
                dp[j]+=dp[j-coins[i]];
            }
        }
        
        return dp[amount];
    }
}
