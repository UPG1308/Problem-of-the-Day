class Solution {
  public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        // Your code here
        int n = arr.size(), count = 0, maxCount = 0, prev = arr[0];
        for(int i = 1; i < n; ++i){
            if(arr[i] > arr[i - 1]) {
                count++;
                maxCount = max(maxCount, count);
            }
            else {count = 0;}
            
            prev = arr[i];
        }
        return maxCount;
    }
};
