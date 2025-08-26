class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        if(s1.size() < s2.size()) swap(s1, s2);
        int n1 = s1.size(), n2 = s2.size();
        
        int j = 0;
        for(int i = 0; i < n1 && j < n2; ++i){
            if(s1[i] == s2[j]) j++;
        }
        return j == n2;
    }
};
