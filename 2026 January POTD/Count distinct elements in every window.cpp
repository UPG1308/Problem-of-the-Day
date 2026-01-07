class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        int n = arr.size(), cnt = 0;
        vector<int> freq(1e5 + 2), ans;
        
        for(int begin = 0, end = 0; end < n; ++end){
            cnt += (++freq[arr[end]] == 1)? 1: 0;
            // cout << cnt << endl;
            if(end - begin + 1 == k){
                ans.push_back(cnt);
                cnt -= (--freq[arr[begin]] == 0)? 1: 0;
                begin++;
            }
        }
        return ans;
    }
};
