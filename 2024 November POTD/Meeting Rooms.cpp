class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Your Code Here
        sort(arr.begin(), arr.end());
        int prevEndTime = -1;
        for(auto it: arr){
            if(it[0] < prevEndTime) return false;
            prevEndTime = it[1];
        }
        return true;
    }
};
