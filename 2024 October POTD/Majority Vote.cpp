class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {

      int n = nums.size();

      int x = n / 3;

      vector<int> cnt;

      unordered_map<int, int> mp;

      for (auto it : nums) {

           mp[it]++;

       }

       for (auto it : mp) {

            if (it.second > x) {

                cnt.push_back(it.first);

              }

        }

        if (cnt.size() == 0) {

            return {-1};

        }

return cnt;

 }
