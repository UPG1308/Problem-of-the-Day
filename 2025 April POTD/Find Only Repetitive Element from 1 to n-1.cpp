class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        // code here
        unordered_map<int,int> mp;
        
        for(auto x:arr){
            mp[x]++;    
        }
        for(auto x:mp){
            if(x.second != 1)
                return x.first;
        }
        return -1;
    }
};
