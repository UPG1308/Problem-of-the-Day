class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<string> st(n);
        for(int i = 0; i < n; ++i) {
            st[i] = to_string(arr[i]);
        }
        
        sort(st.begin(), st.end(), [&](string &a, string &b){
            return a + b >= b + a;
        });
        string s = "";
        for(auto i: st) s += i;
        return s;
    }
};
