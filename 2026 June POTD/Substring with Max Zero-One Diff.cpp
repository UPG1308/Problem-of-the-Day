class Solution {
  public:
    int maxSubstring(string &s) {
        // code here
        int sum = 0, ans = -1, minsum = 0;
        for(int i = 0; i < s.size(); ++i){
            sum += (s[i] == '0')? +1: -1;
            ans = max(ans, sum - minsum);
            minsum = min(minsum, sum);
        }
        return ans;
    }
};
