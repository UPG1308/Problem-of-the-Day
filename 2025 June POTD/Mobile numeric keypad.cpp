class Solution {
  public:
    int getCount(int n) {
        // If sequence length is 0, no sequences possible
        if (n == 0) return 0;
        
        // Define the movement matrix - which digits each digit can move to
        // Index represents current digit, array contains all possible next digits
        vector<vector<int>> moves = {
            {0, 8},           // From 0: can go to 0, 8
            {1, 2, 4},        // From 1: can go to 1, 2, 4
            {1, 2, 3, 5},     // From 2: can go to 1, 2, 3, 5
            {2, 3, 6},        // From 3: can go to 2, 3, 6
            {1, 4, 5, 7},     // From 4: can go to 1, 4, 5, 7
            {2, 4, 5, 6, 8},  // From 5: can go to 2, 4, 5, 6, 8
            {3, 5, 6, 9},     // From 6: can go to 3, 5, 6, 9
            {4, 7, 8},        // From 7: can go to 4, 7, 8
            {0, 5, 7, 8, 9},  // From 8: can go to 0, 5, 7, 8, 9
            {6, 8, 9}         // From 9: can go to 6, 8, 9
        };
        
        // DP arrays: prev stores counts for previous length, curr for current length
        vector<long long> prev(10, 1);  // Base case: 1 way to form length-1 sequence ending at each digit
        vector<long long> curr(10, 0);  // Current iteration results
        
        // For sequences of length 1, each digit has exactly 1 way
        if (n == 1) {
            return 10;  // Sum of all prev values
        }
        
        // Build up sequences of length 2 to n
        for (int len = 2; len <= n; len++) {
            // Reset current array for this iteration
            fill(curr.begin(), curr.end(), 0);
            
            // For each digit position (0-9)
            for (int digit = 0; digit < 10; digit++) {
                // Add ways to reach this digit from all its valid previous positions
                for (int prevDigit : moves[digit]) {
                    curr[digit] += prev[prevDigit];
                }
            }
            
            // Move current results to previous for next iteration
            prev = curr;
        }
        
        // Sum all ways to form sequences of length n ending at any digit
        long long total = 0;
        for (int i = 0; i < 10; i++) {
            total += prev[i];
        }
        
        return total;
    }
};
