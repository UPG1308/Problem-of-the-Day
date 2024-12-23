class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
      bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        for(const auto &row : mat)
            if(binary_search(row.begin(),row.end(),x)) return true;
        return false;
    }
};
