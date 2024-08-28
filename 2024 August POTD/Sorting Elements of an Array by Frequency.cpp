class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        unordered_map<int, int> mp;
        for(int i: arr) mp[i]++;
        sort(arr.begin(), arr.end(), [&](int a, int b){
            if(mp[a] == mp[b]) return a < b;
            return mp[a] > mp[b];
        });
        return arr;
    }
};
