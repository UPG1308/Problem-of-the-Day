class Solution {
  public:
    int totalCount(int k, vector<int>& arr) {
        // code here
        int count = 0;
        for(int num: arr){
            count += (num + k - 1)/k;
        }
        return count;
    }
};
