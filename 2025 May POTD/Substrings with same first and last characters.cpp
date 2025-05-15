class Solution {
  public:
    int countSubstring(string &s) {
        // code here
        map<int, int> mp;
        int count = 0;
        for(char c: s){
            count += mp[c];
            mp[c]++;
        }
        return s.size() + count;
    }
};
