class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        set<int> set;  // storing
        for(int i:a) set.insert(i); // O(m)
        for(int i:b) set.insert(i); // o(n)
        a.clear();
        for(auto i:set) a.push_back(i); // O(n+m)
        return a;
    }
};
