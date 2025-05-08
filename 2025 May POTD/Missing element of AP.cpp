class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int d = 1e9;
        for(int i = 0; i < arr.size() - 1; ++i) {
            if(abs(arr[i + 1] - arr[i]) < abs(d))
            d = arr[i + 1] - arr[i];
        }
        for(int i = 0; i < arr.size(); ++i){
            if(arr[i] != arr[0] + i * d) return arr[0] + i * d;
        }
        return arr.back() + d;
    }
};
