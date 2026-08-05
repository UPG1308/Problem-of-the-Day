class Solution {
  public:
    int countSubarray(vector<int> &arr, int k){
        int count = 0, n = arr.size(), sum = 0;
        for(int begin = 0, end = 0; end <= n; ++end){
            if(end < n) sum += arr[end];
            while(begin <= end && (sum > k || end == n)){
                count += end - begin;
                sum -= arr[begin];
                begin++;
            }
        }
        return count;
    }
    int countSubarray(vector<int>& arr, int l, int r) {
        // code here
        return countSubarray(arr, r) - countSubarray(arr, l - 1);
    }
};
