class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size(), len = 0, start = 0, last = 0;
        multiset<int> st;
        for(int begin = 0, end = 0; end < n; ++end){
            st.insert(arr[end]);
            while(begin <= end && abs(*st.rbegin() - *st.begin()) > x){
                st.erase(st.find(arr[begin++]));
            }
            if(len < end - begin + 1){
                len = end - begin + 1;
                start = begin, last = end;
            }
            
        }
        return vector<int>(arr.begin() + start, arr.begin() + last + 1);
    }
};
