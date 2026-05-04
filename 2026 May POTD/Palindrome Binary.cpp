class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        // code here
        string s = "";
        int b = log2(n);
        
        for(int i = 0; i <= b; ++i){
            s += char('0' + ((n >> i) & 1));
        }
        string t = s;
        reverse(s.begin(), s.end());
        return t == s;
    }
};
