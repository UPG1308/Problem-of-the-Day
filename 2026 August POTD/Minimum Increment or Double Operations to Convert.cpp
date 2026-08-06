class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        // code here
        int count = 0, mx = 0;
        for(int num: arr){
            count += __builtin_popcount(num);
            mx = max(mx, num);
        }
        return count + (__lg(mx));
    }
};
