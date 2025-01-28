class Solution {
  public:
    vector<string> findPermutation(string &s) {
       sort(s.begin(),s.end());
       set<string>st;
       st.insert(s);
       
       while(next_permutation(s.begin(),s.end())) 
            st.insert(s);
           
       return vector<string>(st.begin(),st.end());
    }
};
