class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) {
        // code here
        int n = arr.size(), sum = 0;
        sort(arr.rbegin(), arr.rend());
        
        for(int i = 1; i < n;){
            if(arr[i - 1] - arr[i] < k){
                sum += arr[i - 1] + arr[i];
                i += 2;
            } else i++;
        }
        return sum;
    }
};
