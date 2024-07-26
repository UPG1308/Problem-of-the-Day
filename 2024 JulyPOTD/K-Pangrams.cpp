class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        vector<int> freq(26, 0);
        int count = 0, notAppeared = 26;
        for(int c: str){
            if(c == ' ') continue;
            notAppeared -= (++freq[c - 'a'] == 1)?1:0;
            count += (freq[c - 'a'] == 1)?0:1;
        }
        // cout<<notAppeared<<" "<<count;
        return !notAppeared or (notAppeared <= count and notAppeared <= k);
    }
};
