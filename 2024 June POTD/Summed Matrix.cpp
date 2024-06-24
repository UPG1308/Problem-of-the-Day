class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // code here
        if(q>n*2 || q==1){
            return 0;
        }
       else if(q==2){
            return 1;
        }
        else if (q==n+1){
            return n;
        }
        else if(q<n && q>2){
            return (q-1);
            
        }
        else if (q>n && q<=2*n){
            return ((2*n-q)+1);
        }
        
    }
};
