class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int n = s.size(), count = 0, len = 0;
        vector<int> freq(258);
        for(int begin = 0, end = 0; end < n; ++end){
            count += (++freq[s[end]] == 1)? 1: 0;
            while(end - begin + 1 > count){
                count -= (--freq[s[begin]] == 0)? 1: 0;
                ++begin;
            }
            len = max(len, end - begin + 1);
        }
        return len;
    }
};
