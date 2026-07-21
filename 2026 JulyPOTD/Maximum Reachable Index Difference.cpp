class Solution {
  public:
    int maxIndexDifference(string &s) {
        // code here
        int n = s.size();
        char c = 'a';
        int first = -1, last = -1;
        
        for(int i = 0; i < n; ++i){
            if(s[i] == c){
                c++;
                if(first == -1) first = i;
                last = i;
            }
            else if(s[i] <= c && s[i] != 'a') last = max(last, i);
        }
        
        if(first == -1) return -1;
        return last - first;
    }
};
