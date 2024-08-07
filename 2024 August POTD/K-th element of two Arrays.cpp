class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int n1=(int)arr1.size();
        int n2=(int )arr2.size();
        
        int n=n1+n2;
        
        int low=max(0,k-n2);
        int high=min(n1,k);
        int left=k;
        // basically what we are doing is finding the symmetrical line that can
        // divide the array into two parts with left part having k elements 
        // and right part having n-k elements
        // now for that suppose
        
        /*
           a1 a2 a3(l1) |  a4(r1) a5
              b1 b2(l2) |  b3(r2)
              
            so now to check if it is valid split what we can do
            // is that check if (l1<r2) and (l2<r1). this is because 
            after merging both the arrays the entire array on the left half
            has to be lesser than the right half
            SO this is why we are checking in this manner
            this will ensure that there are exactly k elements on left side
            Now the last element on the left side will be the answer
            last element will be max(l1,l2)
        */
        while(low<=high)
        {
            int mid1=(low+high)/2;
            
            int l1=INT_MIN;
            int l2=INT_MIN;
            int r1=INT_MAX;
            int r2=INT_MAX;
            int mid2=(left-mid1);
            if(mid1<n1)
            {
                r1=arr1[mid1];
            }
            if(mid2<n2)
            {
                r2=arr2[mid2];
            }
            if(mid1>=1)
            {
                l1=arr1[mid1-1];
            }
            if(mid2>=1)
            {
                l2=arr2[mid2-1];
            }
            
            if(l1>r2)
            {
                high=mid1-1;
            }
            else if(l2>r1)
            {
                low=mid1+1;
            }
            else
            {
                return max(l1,l2);
            }
            
        }
        
        return 0;
    }
};
