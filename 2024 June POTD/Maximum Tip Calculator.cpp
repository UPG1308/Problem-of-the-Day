class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // vector which will store the differences between arr and brr
        vector<pair<int, pair<int, int>>> diff;
        
        for(int i=0; i<n; i++){
            // calculated the absolute differences between arr and brr
            diff.push_back({abs(arr[i] - brr[i]), {arr[i], brr[i]}});
        }
        
        // sort the differences in descending order
        sort(diff.rbegin(), diff.rend());
        
        // variaable to calculate maximum tip
        long long mxTip = 0;
        
        for(int i=0; i<n; i++){
            
            long long waiterATip = diff[i].second.first;
            long long waiterBTip = diff[i].second.second;
            
            // add the tip of B when x is zero
            if(x==0){
                y--;
                mxTip += waiterBTip;
            }else if(y==0){
                // add the tip of A when y is zero
                x--;
                mxTip += waiterATip;
            }else{
                // add the tip of waiter which is maximum
                if(waiterATip > waiterBTip){
                    x--;
                    mxTip += waiterATip;
                }else{
                    y--;
                    mxTip += waiterBTip;
                }
            }
        }
        
        return mxTip;
    }
};
