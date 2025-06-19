class Solution {
  public:
    string caseSort(string& s) {
        // code here
        string up = "", lo = "";
        for(char c: s){
            if(isupper(c)) up += c;
            else lo += c;
        }
        
        sort(up.begin(), up.end());
        sort(lo.begin(), lo.end());
        
        int i = 0, j = 0;
        string ans = "";
        
        for(char c: s){
            if(isupper(c)) ans += up[i++];
            else ans += lo[j++];
        }
        return ans;
    }
};
