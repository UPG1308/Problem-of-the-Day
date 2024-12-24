class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>>& mat, int x) {
    int n = mat.size(), m = mat[0].size();

    int lo = 0, hi = n * m - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
      
        // Find row and column of element at mid index
        int row = mid / m;
        int col = mid % m;
      
        // If x is found, return true
        if (mat[row][col] == x) 
            return true;
      
        // If x is greater than mat[row][col], search in
        // right half
        if (mat[row][col] < x) 
            lo = mid + 1;
        
        // If x is less than mat[row][col], search in 
        // left half
        else 
            hi = mid - 1;
    }
    return false;
}
};
