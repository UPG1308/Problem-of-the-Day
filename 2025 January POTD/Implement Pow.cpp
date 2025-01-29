class Solution {
  public:
    double power(double b, int e) {
        // code here
        int p = abs(e);
        double ans = 1;
        while(p){
            if(p%2 == 1){
                ans = ans*b;
            }
            b = b * b;
            p = p >> 1;
        }
        if(e < 0){
            ans = 1 / ans;
        }
        return ans;
    }
};
