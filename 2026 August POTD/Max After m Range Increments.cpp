class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        // code here
        vector<int> pref(n + 1);
        for(int i = 0; i < a.size(); ++i){
            pref[a[i]] += k[i];
            pref[b[i] + 1] -= k[i];
        }
        for(int i = 1; i <= n; ++i){
            pref[i] += pref[i - 1];
        }
        
        return *max_element(pref.begin(), pref.end());
    }
};
