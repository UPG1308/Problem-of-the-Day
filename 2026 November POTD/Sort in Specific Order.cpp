class Solution {
  public:
    void sortIt(vector<int>& arr) {
        int oddIdx = -1, n = arr.size();
        for(int i = 0;i<n;i++){
            if(arr[i]%2)swap(arr[++oddIdx], arr[i]);
        }
        sort(arr.begin(), arr.begin() + oddIdx + 1, greater<int>());
        sort(arr.begin() + oddIdx + 1, arr.end());
    }
};
