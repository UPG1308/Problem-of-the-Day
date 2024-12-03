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
  
    int minChar(string& s) {
        // Write your code here
        string rev = s;
        reverse(rev.begin(), rev.end());
        string ss = s + '$' + rev;
        vector<int> lps = prefix_function(ss);
        return s.size() - lps.back();
        
    }
};
