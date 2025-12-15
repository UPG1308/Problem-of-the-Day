class Solution {
  public:
    int cntWays(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> odd(n + 1), even(n + 1);
        for(int i = 0; i < n; ++i){
            if(i & 1)  odd[i + 1] += arr[i];
            else even[i + 1] += arr[i];
            odd[i + 1] += odd[i];
            even[i + 1] += even[i];
        }
        
        int count = 0;
        for(int i = 0; i < n; ++i){
            int oddsum = 0, evensum = 0;
            if(i & 1){
                oddsum = odd[i] + even[n] - even[i];
                evensum = even[i] + odd[n] - odd[i + 1];
            }
            else {
                oddsum = odd[i] + even[n] - even[i + 1];
                evensum = even[i] + odd[n] - odd[i];
            }
            
            count += oddsum == evensum;
        }
        
        return count;
    }
};
