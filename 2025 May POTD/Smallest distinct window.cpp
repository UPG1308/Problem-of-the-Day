class Solution {
  public:
     int findSubString(string& str) {
        int n = str.length();
       map<char,int> mp;
       set<char> st;
       
       for(auto c : str) st.insert(c);
       
       int l=0,r=0,res=n;
       
       while(r<n){
           mp[str[r]]++;
           
           while(mp.size()==st.size()){
               res=min(res,r-l+1);
               mp[str[l]]--;
               if( mp[str[l]]==0) mp.erase(str[l]);
               l++;
           }
           
           r++;
       }
       
       return res;
        
    }
};
