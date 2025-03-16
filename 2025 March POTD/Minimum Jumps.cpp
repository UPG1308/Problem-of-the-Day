class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // Your code here  
        int n = arr.size(), lastInd = 0, jumps = 0, maxRange = 0;
        for(int i = 0;  i < n; ++i){
            maxRange = max(maxRange, i + arr[i]);
            if(i == lastInd){
                if(maxRange == i){
                    jumps = -1;
                    break;
                }
                lastInd = maxRange;
                jumps++;
                if(lastInd >= n - 1)break;
            }
        }
        return jumps;
    }
};
