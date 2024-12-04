class Solution {
  public:
  
    vector<int> prefix_function(string s) {
        int n = (int)s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Your code here
        string s = s1 + s1;
        string s3 = s2 + '$'+ s;
        vector<int> lps = prefix_function(s3);
        int n = s2.size();
        for(int i = n + 1; i <= s3.size(); ++i){
            if(lps[i] == n) return true;
        }
        return false;
    }
};
