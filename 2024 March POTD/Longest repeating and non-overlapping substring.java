class Solution {
    static String longestSubstring(String s, int n) {
        // Dynamic programming table to store the length of repeating substring ending at each index
        int[][] dp = new int[n][n];

        // Iterate through the string to fill the dp table
        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            for (int j = i + 1; j < n; j++) {
                // Check if the current character is equal to the character at index 'i'
                if (s.charAt(j) == ch) {
                    // If there is a previous occurrence of the character and it doesn't overlap with the current substring
                    if (i > 0 && (j - dp[i - 1][j - 1]) > i) {
                        // Update the length of repeating substring
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else if (i == 0) {
                        // If it's the first occurrence of the character
                        dp[i][j]++;
                    } else {
                        // If there is overlap with the current substring, reset the length
                        dp[i][j] = 0;
                    }
                }
            }
        }

        // Find the maximum length of repeating substring and its starting index
        int maxLen = -1;
        int ind = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (maxLen < dp[i][j]) {
                    ind = i;
                    maxLen = dp[i][j];
                }
            }
        }

        // If no repeating substring is found, return "-1"
        if (maxLen <= 0)
            return "-1";
        
        // Return the longest repeating substring
        return s.substring(ind - maxLen + 1, ind + 1);
    }
};
