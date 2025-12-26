class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int l = 0, r = 1e7;
        
        auto check = [&](int m){
            int ub = upper_bound(arr.begin(), arr.end(), m) - arr.begin();
            return m - ub >= k;
        };
        
        while(r - l > 1){
            int m = l + (r - l)/2;
            if(check(m)) r = m;
            else l = m;
        }
    
        return r;
    }
};
