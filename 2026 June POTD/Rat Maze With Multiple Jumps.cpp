class Solution {
  public:
    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        // code here
        vector<vector<int>> tmp(mat.size(),vector<int>(mat[0].size(),999));
        
        
         for(int m=0;m<mat[0][0];m++)
                {
                    if(m<mat.size())
                    tmp[0][m]=1;
                    if(m<mat[0].size())
                    tmp[m][0]=1;
                }
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==0)continue;
                int mn=tmp[i][j];
                for(int m=1;m<mat[i][j]+1;m++)
                {
                    if(j+m<mat[i].size())
                    tmp[i][j+m]=min(tmp[i][j+m],mn+1);
                    
                    if(i+m<mat.size())
                    tmp[i+m][j]=min(tmp[i+m][j],mn+1);
                }
            }
        }
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size(),0));
        int r=mat.size()-1;
        int c=mat[0].size()-1;
        if(tmp[r][c]==999)return {{-1}};
        int cnt=tmp[r][c];
        while(true)
        {
            //cout<<cnt<<" "<<r<<" "<<c<<endl;
            ans[r][c]=1;
            cnt--;
            bool f=false;
            for(int i=r;i>0;i--){
                if(mat[r-i][c]>0 && tmp[r-i][c]==cnt){
                    f=true;
                    r=r-i;
                    break;
                }
            }
            if(f)
            continue;
            for(int i=c;i>0;i--){
                if(mat[r][c-i]>0 && tmp[r][c-i]==cnt){
                    c=c-i;
                    f=true;
                    break;
                }
            }
            if(f)continue;
            break;
        }
        ans[0][0]=1;
        return ans;
    }
};
