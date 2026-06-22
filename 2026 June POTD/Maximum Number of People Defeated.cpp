class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
        
        auto check = [&](long long n){
            return p >= (n * (n + 1)/2) * (2 * n + 1)/3;
        };
        
        int l = 0, r = 1e3;
        while(r - l > 1){
            int m = l + (r - l)/2;
            if(check(m)) l = m;
            else r = m;
        }
        return l;
    }
};
