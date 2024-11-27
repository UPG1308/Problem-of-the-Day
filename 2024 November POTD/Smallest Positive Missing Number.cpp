class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        unordered_set<int> st(arr.begin(), arr.end());
        for(int i = 1; i <= n; ++i){
            if(st.find(i) == st.end()) return i;
        }
        return n + 1;
    }
};
