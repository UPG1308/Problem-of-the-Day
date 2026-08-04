class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int count = 0;
        for(int i = 0, j = 0; i < n; ++i){
            while(j + 1 < n && arr[j + 1] - arr[i] < k) j++;
            // cout << i << "  " << j << endl;
            count += (j - i);
        }
        return count;
    }
};
