class Solution 
{   static String a;
    static String b;
    static String c;
    static int[][][] h = new int[26][26][26];
    
    int LCSof3(String A, String B, String C, int n1, int n2, int n3) { 
        a = A;
        b = B;
        c = C;
        for (int[][] l : h){
            for (int[] m : l){
                Arrays.fill(m, -1);
            }
        }
        return solve(n1 - 1, n2 - 1, n3 - 1);
    }
    static int solve(int i, int j, int k) {
        if (i == -1 || j == -1 || k == -1) {
            return 0;
        }
        if (h[i][j][k] != -1) {
            return h[i][j][k];
        }
        if (a.charAt(i) == b.charAt(j) && b.charAt(j) == c.charAt(k)) {
            return h[i][j][k] = 1 + solve(i - 1, j - 1, k - 1);
        } else {
            return h[i][j][k] = Math.max(Math.max(solve(i - 1, j, k), solve(i, j - 1, k)), solve(i, j, k - 1));
        }
    }
}
