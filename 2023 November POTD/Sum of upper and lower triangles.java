class Solution
{
    //Function to return sum of upper and lower triangles of a matrix.
    static ArrayList<Integer> sumTriangles(int matrix[][], int n)
    {
        ArrayList<Integer> result=new ArrayList<>();
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                sum=sum+matrix[i][j];
            }
        }
        result.add(sum);
        sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                sum=sum+matrix[i][j];
            }
        }
        result.add(sum);
        return result;
    }
}
