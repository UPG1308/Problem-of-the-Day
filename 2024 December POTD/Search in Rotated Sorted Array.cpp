class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int n = arr.size() - 1;
        while(n >= 0){
            if(arr[n] == key){
                return n;
            }
            n--;
        }
        return -1;
    }
};
