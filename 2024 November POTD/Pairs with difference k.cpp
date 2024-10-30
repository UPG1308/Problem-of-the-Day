class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> mp;
        int ans=0;
        for(auto i:arr){
            int x=i-k;
            int y=i+k;
            ans+=mp.count(x)>0?mp[x]:0;
            ans+=mp.count(y)>0?mp[y]:0;
            
            mp[i]++;
        }
        return ans;
    }
};
