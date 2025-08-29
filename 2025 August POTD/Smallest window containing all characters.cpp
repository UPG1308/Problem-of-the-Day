class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        vector<int> freq(26, 0);
        long long count = 0ll, length = 1e9;
        for(char c: p) count += (freq[c - 'a']++ == 0)?1:0;
        int ind = 0;
        for(int begin = 0, end = 0; end < s.size(); ++end){
            count -= (freq[s[end] - 'a']-- == 1)?1:0;
            while(count == 0 and begin <= end){
                int currlength = end - begin + 1;
                if(currlength < length){
                    length = currlength;
                    ind = begin;
                }
                count += (freq[s[begin++] - 'a']++ == 0)?1:0;
            }
        }
        if(length == 1e9) return "-1";
        return s.substr(ind, length);
    }
};
