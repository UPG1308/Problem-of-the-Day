class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        int i = 0, j = 0, k = 1;
        int totalSize = arr1.size() + arr2.size();
        int first = -1, second = -1;
        while(i < arr1.size() and j < arr2.size()){
            if(arr1[i] <= arr2[j]) {
                if(k == totalSize / 2 and first == -1) first = arr1[i];
                else if(first != -1){
                    second = arr1[i];
                    break;
                }
                i++;
            }
            else {
                if(k == totalSize / 2 and first == -1) first = arr2[j];
                else if(first != -1) {
                    second = arr2[j];
                    break;
                }
                j++;
            }
            k++;
        }
        return (first + second);
    }
};
