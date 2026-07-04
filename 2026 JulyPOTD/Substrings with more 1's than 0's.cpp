#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct BIT {
    vector<int> bit;
    int n;
    BIT(int _n){
        n = _n;
        bit.resize(n + 1, 0);
    }
    
    void update(int ind, int val){
        for(; ind <= n; ind += ind & -ind) bit[ind] += val;
    }
    
    int query(int ind){
        int sum = 0;
        for(; ind > 0; ind -= ind & -ind) sum += bit[ind];
        return sum;
    }
};

class Solution {
  public:
    int countSubstring(string& s) {
        int n = s.size();
        vector<int> pref;
        
        // 1. CRITICAL: Add the initial base case (0) before any characters are processed
        pref.push_back(0); 
        
        int val = 0;
        for(int i = 0; i < n; ++i){
            val += s[i] == '1' ? 1 : -1;
            pref.push_back(val);
        }
        
        // Coordinate Compression
        sort(pref.begin(), pref.end());
        pref.erase(unique(pref.begin(), pref.end()), pref.end());
        
        auto index = [&](int num){
            return lower_bound(pref.begin(), pref.end(), num) - pref.begin();
        };
        
        // Size only needs to be pref.size() + 1 for standard 1-based BIT indexing
        BIT bit(pref.size() + 1); 
        
        // 2. CRITICAL: Insert the base case into the BIT before checking characters
        bit.update(index(0) + 1, 1); 
        
        val = 0;
        int count = 0;
        for(char c : s){
            val += c == '1' ? 1 : -1;
            
            // +1 to convert 0-based compressed index to 1-based BIT index
            int ind = index(val) + 1; 
            
            // Query everything strictly less than current prefix sum
            count += bit.query(ind - 1); 
            
            // Add current prefix sum to the BIT
            bit.update(ind, 1);
        }
        
        return count;
    }
};
