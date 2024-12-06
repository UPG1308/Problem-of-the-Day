class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        // code here
        int n = citations.size();
        sort(citations.rbegin(), citations.rend());
        int i = 0;
        while(i < n && citations[i] >= i + 1) i++;
        return i;
    }
};
