class Solution {
  public:
    int findIndex(string &s) {
        // code here
        int right = count(s.begin(), s.end(), ')');
        int left = 0;
        for(int i = 0; i < s.size(); ++i){
            if(left == right) return i;
            if(s[i] == '(') left++;
            if(s[i] == ')') right--;
        }
        return left == 0? s.size(): -1;
    }
};
