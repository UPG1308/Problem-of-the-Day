class Solution {
  public:
    int minTime(vector<int>& ranks, int n) {
        // code here
        int m = ranks.size();
        int l = 0, r = 1e9 + 1;
        
        auto check2 = [&](int mm, int sum, int d){
            return (2LL * d + 1LL * (mm - 1) * d) * mm / 2 <= sum;
        };
        
        auto check = [&](int mid){
            
            int count = 0;
            for(int i = 0; i < m; ++i){
                count += (long long)(sqrt(1 + 8.0 * mid / ranks[i]) - 1) / 2;
            }
            return count >= n;
        };
        
        while(r - l > 1){
            int mid = l + (r - l)/2;
            if(check(mid)) r = mid;
            else l = mid;
        }
        // assert(r != 1);
        return r;
    }
};
