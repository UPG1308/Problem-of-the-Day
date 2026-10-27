class Solution {
  public:
  vector<int>dp;
  int n;
   int f(int ind,string &s){
       if(ind==(n-1))
       return 1;
       if(ind==n)
       return 0;
       if(dp[ind]!=-1)
       return dp[ind];
       int ans=INT_MIN;
       if(s[ind]==s[ind+1]){
           int temp=4-1+f(ind+2,s);
           ans=max(ans,temp);
           temp=1+f(ind+1,s);
           ans=max(ans,temp);
       }
       else{
           int temp=4+f(ind+2,s);
           ans=max(ans,temp);
           temp=1+f(ind+1,s);
           ans=max(ans,temp);
       }
       return dp[ind]=ans;
   }
    int getMaxWeight(string &s) {
        // code here
         n=s.size();
        dp.resize(n+1,-1);
        return f(0,s);
    }
};
