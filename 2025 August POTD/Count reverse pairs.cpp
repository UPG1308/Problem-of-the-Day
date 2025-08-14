class Solution {
    int count=0;
    private:
    void mergeArray(vector<int> &arr, int  start, int end){
        int  mid= start+(end-start)/2;
        int len1= mid-start+1;
        int len2= end-mid;
        int i= start;
        int j= mid+1;
        
        for (int i = start; i <= mid; i++) {
            while (j <= end && (long long)arr[i] > 2LL * arr[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        int *arr1= new int[len1];
        int *arr2= new int[len2];
        //copyt kar do
        int st= start;
        for(int i=0; i<len1; i++){
            arr1[i]=arr[st++];
        }
        st= mid+1;
        for(int i=0; i<len2; i++){
            arr2[i]= arr[st++];
        }
        
        
         int index1=0;
       int index2=0;
       int arrayIndex= start;
       while(index1 <len1 and index2< len2){
           if(arr1[index1]< arr2[index2]){
               arr[arrayIndex++]= arr1[index1++];

           }
           else{
               arr[arrayIndex++]= arr2[index2++];

           }
       }
       while(index1<len1){
           arr[arrayIndex++]= arr1[index1++];

       }
       while(index2<len2){
           arr[arrayIndex++]= arr2[index2++];

       }
        
    }
    void mergesort(vector<int> &arr, int start,int end){
        if(start>=end){
            return;
        }
        int mid= start+(end-start)/2;
        mergesort(arr, start, mid);
        mergesort(arr, mid+1, end);
        mergeArray(arr, start, end);
    }
  public:
    int countRevPairs(vector<int> &arr) {
        // Code here
         mergesort(arr, 0, arr.size()-1);
         return count;
    }
};
