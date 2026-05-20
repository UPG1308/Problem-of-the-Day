class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        // code here
        set<long long> st;
        for(int i: arr){
            if(target == 0 && i == 0) return true;
            if(i && target % i == 0 && st.count(target / i)) return true;
            st.insert(i);
        }
        return false;
    }
};
