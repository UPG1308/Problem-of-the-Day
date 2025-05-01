class Solution {
  public:
    long long factorial(int n){
        long long res = 1;
        for (int i = 2; i <= n; i++)
            res *= i;
        return res;
        }
        
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        if(n==1) return {1};
        if(n==2) return {1, 1};
        
        vector<int> A;
        A.push_back(1);
        for(int i=1;i<n;i++){
          long long x;
          x=factorial(n-1)/(factorial(i)*factorial(n-1-i));
          A.push_back(x);
         }
         return A;
    }
};
