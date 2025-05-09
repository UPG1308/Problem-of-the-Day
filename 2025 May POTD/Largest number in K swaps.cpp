class Solution {
  public:
    // Function to find the largest number after k swaps.
    void rec(int i, int k, string& s, string& ans){
        int n = s.length();
        if(k == 0 || i == n){
            ans = max(ans, s);
            return;
        }
        
        for(int idx = i; idx < n; idx++){
            if(s[idx] > s[i]){
                swap(s[i], s[idx]);
                rec(i+1, k-1, s, ans);
                swap(s[i], s[idx]);
            }
        }
        
        rec(i+1, k, s, ans);
    }
    
    string findMaximumNum(string& s, int k) {
        string ans = s;
        rec(0, k, s, ans);
        return ans;
    }
};
