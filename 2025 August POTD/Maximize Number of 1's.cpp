class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n = arr.size(), len = 0;
        
        for(int begin = 0, end = 0; end < n; ++end){
            k -= arr[end] == 0? 1: 0;
            while(k < 0){
                k += arr[begin++] == 0? 1: 0;
            }
            len = max(len, end - begin + 1);
        }
        return len;
    }
};
