class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        vector<int> freq(1e5 + 10, 0), ans;
        int n = arr.size(), count = 0;
        
        for(int begin = 0, end = 0; end < n; ++end){
            count += (++freq[arr[end]] == 1)? 1: 0;
            while(end - begin + 1 > k){
                count -= (--freq[arr[begin]] == 0)?1:0;
                begin++;
            }
            if(end - begin + 1 == k) ans.push_back(count);
        }
        return ans;
    }
};
