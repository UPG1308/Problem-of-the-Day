class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        int i = 0, j = -1, previ = -1;
        for(int k = 0;k<arr.size();k++){
            if(arr[k]<=arr[i]){
                i = k;
            }
            else if(j == -1 or arr[k]<=arr[j]){
                j = k;
                previ = i;
            }
            else{
                return vector<int>{arr[previ], arr[j], arr[k]};
            }
        }
        return vector<int>{};
    }
};
