class Solution {
  public:
    
    bool check(int value, int n, int m, int k){
        int count = 0;
        for(int i = 1; i <= n; ++i){
            count += min(m, value / i);
        }
        return count >= k;
    }
  
    int kthSmallest(int m, int n, int k) {
        // code here
        int l = 0, r = n * m + 1;
        while(r - l > 1){
            int mid = l + (r - l)/2;
            if(check(mid, n, m, k)) r = mid;
            else l = mid;
        }
        return r;
    }
};
