class Solution {
  public:
    long long dfs(int node,int n,vector<int> adj[],vector<vector<long long>> &dp)
    {
       if(n==1) return 1;
       if(dp[node][n]!=-1) return dp[node][n];
       long long count=0;
       for(auto it:adj[node])
       {
          count+=dfs(it,n-1,adj,dp);
       }
       return dp[node][n]=count;
    }
    long long getCount(int n) {
        long long count=0;

      //creating adjacency matrix
        vector<int> adj[10];
        adj[0]={0,8};
        adj[1]={1,2,4};
        adj[2]={1,2,3,5};
        adj[3]={2,3,6};
        adj[4]={1,4,5,7};
        adj[5]={2,4,5,6,8};
        adj[6]={3,5,6,9};
        adj[7]={4,7,8};
        adj[8]={5,7,8,9,0};
        adj[9]={6,8,9};
        vector<vector<long long>> dp(10,vector<long long>(n+1,-1));
        for(int i=0;i<=9;i++)
        {
            count+=dfs(i,n,adj,dp);
        }
        return count;
        
    }
