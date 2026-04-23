class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        long long total = accumulate(arr.begin(), arr.end(), 0LL);
        long long sum = 0;
        
        for(int i: arr){
            sum += i;
            total -= i;
            if(sum == total) return true;
        }
        return false;
    }
};
