class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        // code here
        int n = l.size(), m = rank.size(), count = 0;
        vector<int> ans(m), order(m);
        iota(order.begin(), order.end(), 0);
        
        sort(order.begin(), order.end(), [&](int a, int b){
            return rank[a] < rank[b];
        });
        for(int i = 0, j = 0; i < n && j < m; ++i){
            while(j < m && rank[order[j]] - count + l[i] - 1 <= r[i]){
                ans[order[j]] = rank[order[j]] - count + l[i] - 1;
                j++;
            }
            count += (r[i] - l[i] + 1);
        }
        return ans;
    }
};
