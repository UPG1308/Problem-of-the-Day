class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>> ans;
        for(int firstInd = 0; firstInd < n; ++firstInd){
            int target = -arr[firstInd];
            unordered_map<int, vector<int>> mp;
            for(int thirdInd = firstInd + 1; thirdInd < n; ++thirdInd){
                if(mp.find(target - arr[thirdInd]) != mp.end()){
                    auto vec = mp[target - arr[thirdInd]];
                    int size = vec.size();
                    while(size-- > 0){
                        ans.push_back({firstInd, vec.back(), thirdInd});
                        vec.pop_back();
                    }
                }
                mp[arr[thirdInd]].push_back(thirdInd);
            }
        }
        return ans;
    }
};
