class Solution {
  public:
    int dp[1005][1005];
    int fn(vector<int>&coins, int sum, int i){
        
        if(sum==0)return 1;
        if(i>=coins.size())return 0;
        if(dp[sum][i]!=-1)return dp[sum][i];
        
        int ans=0;
        ans+=fn(coins,sum,i+1);
        if(coins[i]<=sum)ans+=fn(coins,sum-coins[i],i); 
    
        return dp[sum][i]=ans;
    }
    int count(vector<int>& coins, int sum) { 
        memset(dp,-1,sizeof(dp));
        return fn(coins,sum,0);
    }
};
