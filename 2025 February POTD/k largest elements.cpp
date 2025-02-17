
class Solution {
  public:
    vector<int> kLargest(vector<int>& nums, int k) {
        // Your code here
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans;

        for(int i=n-1;i>=n-k;i--){
           ans.push_back(nums[i]);
        }
        return ans;
    }
};
