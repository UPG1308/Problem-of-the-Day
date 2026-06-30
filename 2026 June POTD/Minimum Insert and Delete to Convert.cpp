class Solution {
  public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        // code here
        int n = a.size(), m = b.size();
        set<int> st(b.begin(), b.end());
        vector<int> lis;
        for(int num: a){
            if(st.count(num)){
                auto it = lower_bound(lis.begin(), lis.end(), num) - lis.begin();
                if(it == lis.size()) lis.push_back(num);
                else lis[it] = num;
            }
        }
        return (n - lis.size()) + (m - lis.size());
    }
};
