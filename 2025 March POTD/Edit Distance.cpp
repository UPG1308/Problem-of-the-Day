class Solution {
  public:
    int dp[101][101];
    int fun(string s1, string s2, int i, int j){
        if(i==s1.size()){return s2.size()-j;}
        if(j==s2.size()){return s1.size()-i;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int ans=INT_MAX;
        if(s1[i]!=s2[j]){
            ans=min({ans, fun(s1, s2, i, j+1)+1, fun(s1, s2, i+1, j)+1, fun(s1, s2, i+1, j+1)+1});
        }
        else{
            return dp[i][j]=fun(s1, s2, i+1, j+1);
        }
        return dp[i][j]=ans;
    }
    int editDistance(string str1, string str2) {
        memset(dp, -1, sizeof(dp));
        return fun(str1, str2, 0, 0);
    }
};
