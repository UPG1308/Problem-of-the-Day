
class Solution
{
    public int[] antiDiagonalPattern(int[][] matrix)
    {
        int n=matrix.length;
        int m=matrix[0].length;
        
        int[] ans= new int[n*m];
        int idx=0;
        
        for(int i=0;i<(n+m-1);i++){
            for(int row=0;row<Math.min(i+1,n);row++){
                if(i-row<m)
                    ans[idx++]=matrix[row][i-row];
            }
        }
        return ans;

    }
}
