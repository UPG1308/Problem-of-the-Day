class Solution {
  public:
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        // code here
        vector<int> arr;
        int val = 0;
        for(int i = queries.size() - 1; i >= 0; i--){
            int x = queries[i][1];
            if(queries[i][0] == 0) x ^= val, arr.push_back(x);
            else val ^= x;
        }
        arr.push_back(val);
        sort(arr.begin(), arr.end());
        return arr;
    }
};
