class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size(), len = -1, unique = 0;
        vector<int> freq(26);
        for(int begin = 0, end = 0; end < n; ++end){
            unique += (++freq[s[end] - 'a'] == 1)? 1: 0;
            while(begin <= end && unique > k) unique -= (--freq[s[begin++] - 'a'] == 0)? 1: 0;
            if(unique == k) len = max(len, end - begin + 1);
        }
        return len;
    }
};
