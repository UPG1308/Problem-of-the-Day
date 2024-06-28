class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int n = arr.size();
        string ans = "";
        for(int i = 0; i < n; i++){
            if(isRowPalindrome(i, arr, n)) return {to_string(i) + " R"};
        }
        for(int j = 0; j < n; j++){
            if(isColPalindrome(j, arr, n)) return {to_string(j) + " C"};
        }
        return "-1";
    }
    bool isRowPalindrome(int row, vector<vector<int>> &arr, int n){
        int i = 0;
        while(i <= n/2){
            if(arr[row][i] != arr[row][n - i - 1]) return false;
            i++;
        }
        return true;
    }
    bool isColPalindrome(int col, vector<vector<int>>& arr, int n){
        int j = 0;
        while(j <= n/2){
            if(arr[j][col] != arr[n - j - 1][col]) return false;
            j++;
        }
        return true;
    }
};
