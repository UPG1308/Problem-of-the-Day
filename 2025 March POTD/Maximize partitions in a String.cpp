class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        int n = s.size();
        vector<int> lastOccurrence(26);
        for(int i = 0; i < n; ++i) lastOccurrence[s[i] - 'a'] = i;
        int partitionEnd = 0, count = 0;
        for(int i = 0; i < n; ++i){
            partitionEnd = max(partitionEnd, lastOccurrence[s[i] - 'a']);
            if(partitionEnd == i) count++;
        }
        return count;
    }
};
