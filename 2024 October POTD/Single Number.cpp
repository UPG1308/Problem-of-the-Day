class Solution {
  public:
    int getSingle(vector<int>& arr) {
        // code here
        int xora = 0;
        for(int num: arr) xora ^= num;
        return xora;
    }
};
