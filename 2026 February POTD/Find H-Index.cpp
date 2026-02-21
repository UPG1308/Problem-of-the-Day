class Solution {
  public:
    int hIndex(vector<int>& arr) {
        int n = arr.size();
        vector<int> mp(n+1);
        for(int i = 0;i<n;i++){
            if(arr[i]>n){
                mp[n]++;
            }
            else{
                mp[arr[i]]++;
            }
        }
        
        for(int i = n-1;i>=0;i--)
        {
            mp[i] += mp[i+1];
        }
        int res = 0;
        for(int i = 0;i<=n;i++){
            if((i)<=mp[i])res = (i);
        }
        
        return res;
    }
};
