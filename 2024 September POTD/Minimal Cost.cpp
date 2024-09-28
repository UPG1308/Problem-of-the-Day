class Solution {
  public:
    // Recursive helper function to calculate minimum cost
    int help(int ind, int k, vector<int> &arr, vector<int> &dp) {
        // Base case: If we reach or exceed the last index, no more cost is needed
        if(ind >= arr.size() - 1) return 0;

        // If we've already calculated the result for this index, return it from dp[]
        if(dp[ind] != -1) return dp[ind];

        // Initialize the minimum cost for the current index as a very large value
        int ans = INT_MAX;

        // Loop through all possible jumps (1 to k steps)
        for(int i = 1; i <= k; ++i) {
            // Check if the jump doesn't exceed the array bounds
            if(ind + i < arr.size()) {
                // Calculate the cost for the current jump
                int temp = abs(arr[ind + i] - arr[ind]) + help(ind + i, k, arr, dp);

                // Update the minimum cost if this jump results in a lower cost
                ans = min(ans, temp);
            }
        }

        // Store the result for the current index in dp[] and return it
        return dp[ind] = ans;
    }

    // Main function to minimize the cost of jumping through the array
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        // Initialize the dp array with -1 (indicating that results are not yet calculated)
        vector<int> dp(n + 1, -1);

        // Start the recursion from index 0
        return help(0, k, arr, dp);
    }
};
