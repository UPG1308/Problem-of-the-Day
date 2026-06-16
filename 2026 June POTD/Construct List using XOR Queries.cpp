class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        // code here
        vector<int> ans;
        int xor_val = 0;
        for(auto it: queries){
            if(it[0] == 1) xor_val ^= it[1];
        }
        
        ans.push_back(xor_val);
        for(auto it: queries){
            if(it[0] == 0){
                ans.push_back(it[1] ^ xor_val);
            } else {
                xor_val ^= it[1];
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
