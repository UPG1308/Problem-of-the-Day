class Solution{
    public int minStep(int n)
    {
        // code here
        return dp(n) - 1;
    }
    
    public int dp(int i){
        if (i <= 0){
            return 0;
        }
        
        if (i % 3 == 0){
            return 1 + dp(i / 3);
        }
        
        else{
            return 1 + dp(i-1);
        }
    }
