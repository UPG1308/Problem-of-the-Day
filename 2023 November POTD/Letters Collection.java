class Solution{
    static List<Integer> matrixSum(int n, int m, int mat[][], int q, int queries[][])
    {   List<Integer> ans=new LinkedList<>();
        int k=0,sum=0;
        while(k<q){
        int z=queries[k][0];
        int x=queries[k][1]-z;
        int y=queries[k][2]-z;
        int tempx=x,tempy=y;
        if((x>=0 && x<n) && (y>=0 && y<m)) sum-=mat[x][y];
       for(int i=0;i<=z*2;i++){
           if((tempx>=0 && tempx<n) &&(tempy>=0 && tempy<m)){
               sum+=mat[tempx][tempy];
           }
           if((x>=0 && x<n) && (y<m && y>=0)){
               sum+=mat[x][y];
           }
           tempy++;
           x++;
       }
        
        z=queries[k][0];
        x=queries[k][1]+z;
        y=queries[k][2]+z;
        tempx=x;
        tempy=y;
        if((x>=0 && x<n) && (y>=0 && y<m)) sum-=mat[x][y];
       for(int i=0;i<z*2;i++){
           if((tempx>=0 && tempx<n) &&(tempy>=0 && tempy<m)){
               sum+=mat[tempx][tempy];
           }
           if((x>=0 && x<n) && (y<m && y>=0)){
               sum+=mat[x][y];
           }
           tempx--;
           y--;
       }
       k++;
       ans.add(sum);
       sum=0;
    }
    return ans;
    }
}
