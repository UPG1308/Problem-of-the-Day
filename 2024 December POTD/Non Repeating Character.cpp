class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        // Your code here
        vector<int> f(26,0);
        for(auto c : s){
            f[c-'a']++;
        }
        for(auto c : s){
            if(f[c-'a']==1){
                return c;
            }
        }
        return '$';
    }
};
