class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        int n = arr.size();
        for(int i = 1; i < n - 1; ++i){
            if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) return arr[i];
        }
        
        if(arr[0] > arr[1]) return arr[0];
        return arr[n - 1];
    }
};
