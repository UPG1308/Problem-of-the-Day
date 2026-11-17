class Solution {
  public:
    bool findPattern(string& s) {
           int c = 0;
           for(auto it:s){
               if(it == 'x') c++;
               else c--;
               if(c < 0) return false;
           }
           return c == 0;
       }
};
