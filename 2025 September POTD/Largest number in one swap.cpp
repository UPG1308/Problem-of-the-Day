class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        string temp = s;
        sort(temp.rbegin(), temp.rend());
        
        for(int i = 0; i < s.size(); ++i){
            if(s[i] != temp[i]){
                int ind = s.size() - 1;
                for(; ind >= i; --ind){
                    if(s[ind] == temp[i]) break;
                }
                swap(s[i], s[ind]);
                return s;
            }
        }
        return s;
    }
};
