class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        // code here
        long long sum = accumulate(arr.begin(), arr.end(), 0ll);
        if(sum % 3 != 0) return {-1, -1};
        
        int i = 0, j = 0, currsum = 0;
        vector<int> ans(2, -1);
        while(i < arr.size()){
            currsum += arr[i];
            if(currsum == sum / 3){
                currsum = 0;
                ans[j++] = i;
            }
            else if(currsum > sum / 3) return {-1, -1};
            ++i;
        }
        return ans;
    }
};
