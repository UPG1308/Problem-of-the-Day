class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n = a.size(), m = b.size();
        int i = 0, j = 0, last = 0;
        while(k--){
            if(i == n){
                last = b[j++] ;
            } else if(j == m) {
                last = a[i++];
            } else if(a[i] < b[j]){
                last = a[i++];
            } else {
                last = b[j++];
            }
        }
        return last;
    }
};
