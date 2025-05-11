class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        vector<int> allSums;
        for(int i = 0; i < arr.size(); i++) {
            int sum = 0;
            for(int j = i; j < arr.size(); j++) {
                sum += arr[j];
                allSums.push_back(sum);  // include duplicates
            }
        }

        // Sort all sums in descending order
        sort(allSums.begin(), allSums.end(), greater<int>());

        // k-th largest sum is at index k-1
        return allSums[k - 1];
    }
};
