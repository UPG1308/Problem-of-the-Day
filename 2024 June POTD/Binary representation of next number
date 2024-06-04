class Solution {
  public:
    string binaryNextNumber(string s) {
        int n = s.size(), i = n-1;
        // convert all trailing '1' -> '0'
        while(i >= 0 && s[i] == '1') s[i--] = '0';
        // convert the first '0' -> '1'
        if(i == -1) s = "1" + s;
        else s[i] = '1';
        // remove the front '0'
        int f = 0;
        while(s[f] == '0') f++;
        return s.substr(f);
    }
};
