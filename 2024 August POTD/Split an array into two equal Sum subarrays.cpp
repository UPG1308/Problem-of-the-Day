#define ll long long

class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        vector<ll> prefix(n + 1, 0ll);
        
        for(int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + arr[i];
        
        for(int i = 0; i < n; ++i){
            if(prefix[i] == prefix[n] - prefix[i]) return true;
        }
        return false;
    }
};
