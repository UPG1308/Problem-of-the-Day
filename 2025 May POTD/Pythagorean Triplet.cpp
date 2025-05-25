class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int num:arr){
            mp[num*num]++;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int num1=arr[i]*arr[i];
                int num2=arr[j]*arr[j];
                if(mp.find(num1+num2)!=mp.end()){
                    return true;
                }
            }
        }
        return false;
    }
};
