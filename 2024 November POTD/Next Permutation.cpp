class Solution {
  public:
    void nextPermutation(vector<int>& nums) {
        int index=-1;
        if(nums.size()==1) return;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
        if(index!=-1){
            for(int i=nums.size()-1;i>=index+1;i--){
                if(nums[i]>nums[index]){
                    swap(nums[i],nums[index]);
                    break;
                }
            }
        }
        int l=index+1;
        int r=nums.size()-1;
        while(l<=r){
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
    }
};
