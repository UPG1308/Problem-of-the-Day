class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        int l = 0, m = 0, r = n - 1;
        while(m <= r){
            if(arr[m] == 0) swap(arr[m++], arr[l++]);
            else if(arr[m] == 1) m++;
            else swap(arr[r--], arr[m]);
        }
    }
};
