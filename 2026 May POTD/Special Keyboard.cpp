class Solution {
    public int optimalKeys(int n) {
        // code here
        return func(n);
    }
    private int func(int n){
        if(n<=0) return 0;
        
        int addA=func(n-1)+1;
        
        for(int j=1;j<=n-3;j++){
            int current=func(j)*func(n-j-1);
            
            addA=Math.max(addA,current);
        }
        return addA;
    }
}
