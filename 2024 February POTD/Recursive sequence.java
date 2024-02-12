class Solution{
    static long mod = (long) 1e9 + 7;
    static long sequence(int n){
        // code here
        return fun(n);
    }
    static long fun(int n){
        if(n == 1) return 1;
        return (fun(n - 1) + mul(n, (n * (n + 1)/2))) % mod;
    }
    static long mul(int n, int end){
        long ans = 1;
        for(; n > 0; end--, n--) ans = (ans * end)%mod;
        return ans;
    }
}
