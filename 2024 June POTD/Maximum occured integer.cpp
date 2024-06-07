class Solution {
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) {

        // Your code here
        int siz = maxx + 3;
        vector<int> arr(siz, 0);
        for(int i = 0;i < n; i++) arr[l[i]]++;
        for(int i = 0;i < n; i++) arr[r[i] + 1]--;
        for(int i = 1; i < siz; i++) arr[i] += arr[i - 1];
        int count = 0, mn = 0;
        for(int i = 0; i < siz; i++){
            if(arr[i] > count){
                count = arr[i];
                mn = i;
            }
        }
        return mn;
    }
};
