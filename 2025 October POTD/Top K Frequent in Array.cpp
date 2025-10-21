class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        vector<int> freq(1e5 + 2), index;
        for(int i = 0; i < n; ++i) freq[arr[i]]++;
        
        for(int i = 0; i <= 1e5; ++i){
            if(freq[i]) index.push_back(i);
        }
        
        sort(index.begin(), index.end(), [&](int i, int j){
            if(freq[i] == freq[j]) return i > j;
            return freq[i] > freq[j];
        });
        
        n = index.size();
        vector<int> ans;
        for(int i = 0; i < min(n, k); ++i){
            ans.push_back(index[i]);
        }
        return ans;
    }
};
