class Solution
{
    static int dp[][];
    public static int wordBreak(int len, String s, ArrayList<String> dictionary )
    {
        //code here
        int n = s.length();
        dp = new int[n + 1][n + 1];
        for(int[] i: dp) Arrays.fill(i, -1);
        HashSet<String> set = new HashSet<>(dictionary);
        return helper(0, s.length() - 1, set, s)? 1:0;
        
    }
    
    public static boolean helper(int start,int end, HashSet<String> set, String s){
        
        if(start > end) return true;
        if(dp[start][end] != -1) return dp[start][end] == 1;
        boolean flag = false;
        for(int i = start; i <= end; i++){
            String sub = s.substring(start, i + 1);
            
            if(set.contains(sub)){
                flag |= helper(i + 1, end, set, s);
            }
        }
        dp[start][end] = flag?1:0;
        return flag;
    }
}
