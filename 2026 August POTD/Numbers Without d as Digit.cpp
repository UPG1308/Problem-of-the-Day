#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
private:
    long long dp[15][2][2];
    string s;
    int d;

    long long solve(int idx, int tight, int lz) {
        // Base case: successfully formed a number
        if (idx == s.length()) return 1;
        
        // Return cached result
        if (dp[idx][tight][lz] != -1) 
            return dp[idx][tight][lz];

        long long ans = 0;
        int limit = tight ? (s[idx] - '0') : 9;

        for (int digit = 0; digit <= limit; digit++) {
            // Check if it's the forbidden digit
            if (digit == d) {
                // We can safely use 0 if it acts as a leading zero placeholder
                if (d == 0 && lz) {
                    // Do nothing, allow it to pass
                } else {
                    continue; // Skip this digit
                }
            }
            
            // Move to the next digit
            int new_tight = tight && (digit == limit);
            int new_lz = lz && (digit == 0);
            ans += solve(idx + 1, new_tight, new_lz);
        }
        
        return dp[idx][tight][lz] = ans;
    }
    
public:
    long long countNumbers(long long n, int d) {
        s = to_string(n);
        this->d = d;
        memset(dp, -1, sizeof(dp));
        
        // Count all valid paths and subtract 1 (since the problem asks from 1 to n)
        return solve(0, 1, 1) - 1;
    }
};
