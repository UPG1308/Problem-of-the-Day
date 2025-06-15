class Solution {
  public:
    
    bool check(int m, vector<int> &arr, int n, int k){
        int sum = 0;
        for(int i: arr){
            sum += (i + m - 1)/m;
            if(sum > k) return false;
        }
        return sum <= k;
    }
    
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int n = arr.size(), l = 0, r = 1e6 + 1;
        
        while(r - l > 1){
            int m = l + (r - l)/2;
            if(check(m, arr, n, k)) r = m;
            else l = m;
        }
        return r;
    }
};
