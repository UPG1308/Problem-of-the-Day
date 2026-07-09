class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
        map<int, int> mp;
        int count = 0;
        for(int num: arr){
            count += mp[(k - num % k) % k];
            mp[num % k]++;
        }
        return count;
    }
};
