class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        sort(b.begin(), b.end());
        
        int n = a.size();
        vector<int> ans(n);
        
        for(int i = 0; i < n; ++i){
            ans[i] = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        }
        return ans;
        
    }
};
