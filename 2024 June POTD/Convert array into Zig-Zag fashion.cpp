class Solution {
  public:
    void zigZag(int n, vector<int> &arr) {
        bool leftsmall = true;
        for(int i = 0; i<(n-1) ; i++){
            if(leftsmall){
                //we want arr[i] < arr[i+1]
                if(arr[i] > arr[i+1]){
                    swap(arr[i] , arr[i+1]);
                }
            }else{
                //we want arr[i] > arr[i+1]
                if(arr[i] < arr[i+1]){
                    swap(arr[i] , arr[i+1]);
                }
            }
            
            leftsmall = !leftsmall;
        }
        
    }
};
