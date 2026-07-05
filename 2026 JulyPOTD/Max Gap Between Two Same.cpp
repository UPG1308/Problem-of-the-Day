class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        int n = s.size();
        vector<int> first(26, -1);
        int count = -1;
        
        for(int i = 0; i < n; ++i){
            
            if(first[s[i] - 'a'] == -1) first[s[i] - 'a'] = i;
            else count = max(count, i - 1 - first[s[i] - 'a']);
        }
        return count;
    }   
};
