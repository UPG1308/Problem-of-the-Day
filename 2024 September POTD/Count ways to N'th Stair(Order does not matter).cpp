class Solution{
	public:
		int nthStair(int n){
		    //  Code here
		    vector<vector<int>> dp(3, vector<int>(n + 2, 0));
		    dp[1][0] = dp[2][0] = 1;
		    for(int ind = 1; ind <= 2; ++ind){
		        for(int stair = 1; stair <= n; ++stair){
		            int step = 0;
		            if(stair - ind >= 0) step = dp[ind][stair - ind];
		            dp[ind][stair] = step + dp[ind - 1][stair];
		        }
		    }
		    return dp[2][n];
		}
};
