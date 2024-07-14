class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int cnt0 = 0;
        int cnt1 = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                cnt0++;
            }
            else{
                cnt1++;
            }
        }
        int x = 0;
        for(int i=0;i<cnt0;i++){
            arr[x]=0;
            x++;
        }
        for(int i=0;i<cnt1;i++){
            arr[x]=1;
            x++;
        }
    }
};
