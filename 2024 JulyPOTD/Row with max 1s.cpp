class Solution {

public:
    int rowWithMax1s(vector<vector<int>>& a) {
        int maxi = 0, ans = -1;
        for (int i = 0; i < a.size(); i++) {
            int p = upper_bound(a[i].begin(), a[i].end(), 0) - a[i].begin();
            if (maxi < a[0].size() - p) {
                ans = i;
                maxi = a[0].size() - p;
            }
        }
        return ans;
    }
};
