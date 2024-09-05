class Solution {
  public:

    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {

        // Your code goes here
        return (n * (n + 1)/2) - accumulate(arr.begin(), arr.end(), 0);
    }
};
