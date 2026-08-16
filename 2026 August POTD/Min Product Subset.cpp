class Solution {
  public:
    int minProd(vector<int>& arr) {
        // code here
        int neg = 1, pos = 1, mx = -11, mn = 11, zero = 0;
        for(int num: arr){
            if(num < 0){
                neg *= num;
                mx = max(mx, num);
            }
            else if(num > 0){
                pos *= num;
                mn = min(mn, num);
            }
            else zero++;
        }
        
        if(mx != -11){
            if(neg < 0) return pos * neg;
            return pos * neg / mx;
        }
        return zero? 0: mn;
    }
};
