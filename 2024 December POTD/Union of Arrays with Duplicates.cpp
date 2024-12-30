class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int> st(a.begin(), a.end());
        int count = 0;
        for(int num: b) st.insert(num);
        return st.size();
    }
};
