class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        vector<int> occ(1e6 + 1);
        for(int i: arr) {
            if(i > 0) occ[i] = i;
        }
        for(int i = 1; i <= 1e6; ++i) {
            if(!occ[i]) return i;
        }
        return -1;
    }
};
