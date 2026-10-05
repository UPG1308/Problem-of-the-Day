class Solution {
  public:
    int X[4]={-1, 0, 1, 0};
    int Y[4]={0, 1, 0, -1};
  
    virtual int getCount(int i, int j, vector<vector<int>> &matrix,
                             int n, int m, vector<vector<bool>> &visited, vector<vector<int>> &dp){
      
      if(dp[i][j]!=-1) return dp[i][j];
      
      visited[i][j]=true;
      int ans=1;
      
      for(int k=0; k<4; k++){
        int ni=i+X[k];
        int nj=j+Y[k];
        
        if(ni>=0 && nj>=0 && ni<n && nj<m && (!visited[ni][nj]) && (matrix[ni][nj] > matrix[i][j])){ 
                       ans=max(ans, 1+getCount(ni, nj, matrix, n, m, visited, dp));}
      }
      
      visited[i][j]=false;
      return dp[i][j]=ans;                           
    }
    
    virtual int longIncPath(vector<vector<int>> &matrix, int n, int m){
       vector<vector<int>> dp(n, vector<int>(m, -1));
       vector<vector<bool>> visited(n, vector<bool>(m, false));
       
       int ans=1;
       
       for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
           ans=max(ans, getCount(i, j, matrix, n, m, visited, dp));    
         }
       }
       
       return ans;
    }
};
