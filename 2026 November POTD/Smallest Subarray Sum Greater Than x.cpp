class Solution {
  public:
    int smallestSubWithSum(vector<int>& arr, int x) {
            if(accumulate(arr.begin(), arr.end(),0)<=x){return 0;}
            int i=0, j=0, sum=0, ans=arr.size();
            while(i<arr.size()){
                sum+=arr[i++];
                while(sum>x){ans=min(ans, i-j); sum-=arr[j++]; }
            }
            return ans;
        }
};
