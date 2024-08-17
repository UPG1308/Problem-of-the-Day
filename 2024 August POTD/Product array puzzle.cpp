#define ll long long
class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        int n = nums.size();
        ll prod = 1, zero = 0;
        for(ll i: nums) {
            if(i == 0){zero++; continue;}
            prod *= i * 1ll;
        }
        vector<ll> ans(n, 0);
        for(int i = 0; i < n; ++i) {
            if(nums[i] == 0){
                if(zero >= 2) ans[i] = 0;
                else ans[i] = prod;
            }
            else if(zero > 0) continue;
            else ans[i] = prod / nums[i];
        }
        return ans;
    }
};
