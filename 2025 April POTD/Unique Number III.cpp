class Solution {
  public:
     int getSingle(vector<int> &arr) {
        map<int,int>count;
        int res = 0 ;
        for(int i =0;i<arr.size();i++){
            count[arr[i]]++;
        }
        for(auto &a:count){
            if(a.second == 1){
                res = a.first;
        }
        }
        return res;
        
    }
};
