class Solution {
    int findMaxSum(int n, int m, int mat[][]) {
        // code here
        if( m<3 || n<3)return -1;
        int maxSum=Integer.MIN_VALUE;
        
        for(int i=0;i+2<n;++i){
            for(int j=0;j+2<m;++j){
                int sum=mat[i][j]+
                mat[i][j+1]+mat[i][j+2]+
                mat[i+1][j+1]+mat[i+2][j]+
                mat[i+2][j+1]+mat[i+2][j+2];
                if(sum>maxSum)maxSum=sum;
                
            }
        }
        return maxSum;
    }
};
