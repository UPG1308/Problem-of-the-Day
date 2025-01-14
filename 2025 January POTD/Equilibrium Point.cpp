class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int n = arr.size(), pref = 0;
        
        for(int i = 0; i < n; ++i){
            if(pref == sum - pref - arr[i]) return i;
            pref += arr[i];
        }
        return -1;
    }
};
