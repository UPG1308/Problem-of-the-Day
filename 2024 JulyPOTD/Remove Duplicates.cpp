class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        vector<int> freq(26, 0);
        string st = "";
        for(char c: str){
            if(freq[c - 'a'] == 0) st += c;
            freq[c - 'a']++;
        }
        return st;
    }
};
