class Solution {
    static int firstElement(int n) {
        // code here
        int mod = 1000000007;
        if(n==0  || n==1){
            return n;
        }
        int a =1;
        int b =1;
        int sum=1;
        for(int i=2;i<n;i++){
            
            sum = (a+b)%mod;
            a = b;
            b = sum;
        }
        return sum%mod;
    }
}
