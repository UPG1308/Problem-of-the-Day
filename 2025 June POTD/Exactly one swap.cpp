class Solution {
  public:
    int countStrings(string &s) {
        // code here
        int n = s.size();
        map<char, int> mp;
        for(char c: s) mp[c]++;
        
        int count = 0, cnt = 0;
        for(char c: s) {
            if(mp[c] > 1) cnt = 1;
            count += n - mp[c];
        }
        
        return count / 2 + cnt;
    }
};
