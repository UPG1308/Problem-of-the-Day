class Solution {
  public:
    
    struct BIT{
        vector<int> bit;
        int n;
        BIT(int __n){
            n = __n;
            bit.resize(n + 1);
        }
        
        void addValue(int ind, int val){
            for(; ind <= n; ind += ind & -ind) bit[ind] += val;
        }
        
        int getSum(int ind){
            int sum = 0;
            for(; ind; ind -= ind & -ind) sum += bit[ind];
            return sum;
        }
    };
  
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());
        
        auto getIndex = [&](int i){
            return int(lower_bound(temp.begin(), temp.end(), i) - temp.begin()) + 1;
        };
        
        int count = 0;
        BIT bit(temp.size());
        for(int i = 0; i < n; ++i){
            count += (bit.getSum(temp.size()) - bit.getSum(getIndex(arr[i])));
            bit.addValue(getIndex(arr[i]), 1);
        }
        
        return count;
    }
};
