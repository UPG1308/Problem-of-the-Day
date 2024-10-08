class Solution {
  public:
    int getMinDiff(std::vector<int> &arr, int k) {
        if (arr.empty()) return 0; // Handle empty input case
        
        std::sort(arr.begin(), arr.end()); // Sort the array
        
        int n = arr.size();
        int minDiff = arr[n-1] - arr[0]; // Initial difference without any adjustment
        // Iterate through the sorted array and calculate the possible minimum difference
        for (int i = 1; i < n; ++i) {
            if (arr[i] < k) continue; // Skip cases where adjustment exceeds element
            int minValue = std::min(arr[0] + k, arr[i] - k); // Adjust minimum value
            int maxValue = std::max(arr[n-1] - k, arr[i-1] + k); // Adjust maximum value            
            minDiff = std::min(minDiff, maxValue - minValue); // Update minimum difference
        }
        
        return minDiff;
    }
};
