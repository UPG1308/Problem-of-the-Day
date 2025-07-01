class Solution {
  public:
  
    int substrCount(string &s, int k) {
        // code here
        int n = s.size(), distinct = 0, count = 0;
        vector<int> freq(26);
        
        for(int begin = 0, end = 0; end < n; ++end){
            distinct += (++freq[s[end] - 'a'] > 1)? 1: 0;
            if(end - begin + 1 > k) distinct -=(--freq[s[begin++] - 'a'] >= 1)? 1: 0;
            
            if(end - begin + 1 == k && distinct == 1) count++;
        }
        return count;
    }
};
