lass Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        // Your code here
        unordered_map<long long, long long> mp;
        long long count = 0, prefsum = 0;
        mp[0] = 1;
        for(long long num: arr){
            prefsum += num;
            if(mp.count(prefsum - tar)) {
                long long sum = mp[prefsum - tar];
                count += sum;// * (sum + 1)/2;
            }
            mp[prefsum]++;
        }
        return count;
    }
};
