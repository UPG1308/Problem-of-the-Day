class Solution {
  public:
    long long atmost(string& s, int k){
        int n = s.size();
        vector<int> freq(26);
        long long unique = 0, count = 0;
        for(int begin = 0, end = 0; end < n; ++end){
            unique += ++freq[s[end] - 'a'] == 1? 1: 0;
            while(begin <= end && unique > k){
                unique -= --freq[s[begin++] - 'a'] == 0? 1: 0;
            }
            count += 1ll * end - begin + 1;
        }
        return count;
    }
    int countSubstr(string& s, int k) {
        // code here
        return atmost(s, k) - atmost(s, k - 1);
    }
};
