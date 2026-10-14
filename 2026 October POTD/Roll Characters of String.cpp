class Solution {
  public:
    string findRollOut(string& s, vector<int>& roll) {
            // code here
            vector<int>mp(s.size(),0);
            for(auto it:roll){
                mp[it-1]++;
            }
            for(int i = s.size()-2 ; i >= 0;i--){
                mp[i] += mp[i+1];
            }
            int mul = 0;
            for(int i = 0;i<s.size();i++){
                int index = s[i]-'a';
                index += mp[i];
                index = index %26;
                s[i] = 'a'+index;
            }
            return s;
        }
};
