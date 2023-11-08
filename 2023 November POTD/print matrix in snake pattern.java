class Solution
{
    //Function to return list of integers visited in snake pattern in matrix.
    static ArrayList<Integer> snakePattern(int matrix[][])
    {
        // code here 
        int n = matrix.length;
        int m = matrix[0].length;
        ArrayList<Integer> list = new ArrayList<>();
        boolean leftToRight = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(leftToRight) list.add(matrix[i][j]);
                else list.add(matrix[i][n - 1 - j]);
            }
            leftToRight = !leftToRight;
        }
        return list;
    }
}
