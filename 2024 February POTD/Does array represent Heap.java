class Solution {
    
    public boolean countSub(long arr[], long n)
    { 
        for(int i=0;i<n;i++){
           if(i+i+1<n && arr[i]<arr[i+i+1]) return false;
           if(i+i+2<n && arr[i]<arr[i+i+2]) return false;
        }
        return true;
    }
}
