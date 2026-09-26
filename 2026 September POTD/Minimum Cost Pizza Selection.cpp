class Solution {
  public:
    int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        // code here
           int mn=1e9;
           
           int n=(x+s-1)/s,me=(x+m-1)/m,k=(x+l-1)/l;
           
           for(int i=0;i<=n;i++)
           {
               for(int j=0;j<=me;j++)
               {
                   for(int y=0;y<=k;y++)
                   {
                       int required_area=(i*s+j*m+y*l);
                       if(required_area>=x)
                       {
                           int cost=i*cs+j*cm+y*cl;
                           mn=min(mn,cost);
                       }
                   }
               }
           }
           
           return mn;
    }
};

