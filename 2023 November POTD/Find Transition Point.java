class Solution {
    int transitionPoint(int arr[], int n) {
        // code here
        int low = 0, high = n - 1;
        boolean flag = true;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] == 0) low = mid + 1;
            else {
                high = mid - 1;
                flag = false;
            }
        }
        if(flag) return -1;
        return low;
    }
}
