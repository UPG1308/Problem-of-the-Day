class Solution {
  public:
    string reverseWords(string str) {
        vector<string> v;
        string temp="";
        string ans="";
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='.'){
                v.push_back(temp);
                temp="";
            }
            else{
                temp+=str[i];
            }
        }
        v.push_back(temp);
        for(int i=v.size()-1;i>=1;i--)
        {
            ans+=v[i]+'.';
        }
        ans+=v[0];
        return ans;
    }
};
