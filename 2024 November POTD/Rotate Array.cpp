class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
     void rotateArr(vector<int>& arr, int d) {
        // code here
           int n =arr.size();
           int val=d/n;
           int ntime=d-(n*val);
           
           vector<int>v=arr;
           int k=n-1;
           for(int i=0;i<ntime;i++){
            arr[n-ntime+i]=v[i];   
            k--;
           }
           k=ntime;
            for(int i=0;i<n-ntime;i++){
            arr[i]=v[k];   
            k++;
           }
           
           
    }


};
