class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
         int n = arr.size();
        int fpro = 1;
        int bpro = 1;
        int max = -1e7;
        for(int i =0,j=n-1;i<n;i++,j--){
            fpro *=arr[i];
            bpro *=arr[j];
            if(bpro>max){
                max = bpro;
                
            }
            if(fpro>max){
                max = fpro;
            }
              if(fpro==0){
                fpro = 1;
            }
            if(bpro==0){
                bpro = 1;
            }

        }
        return max;
    }
};
