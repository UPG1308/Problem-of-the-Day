class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
        int n=arr.size();
        int ind=0;
        vector<vector<int>>ans;
        int x=0;
        while(true){
            vector<int>tmp;
            int sz=(1<<x);
            x++;
            for(int i=0 ;i<sz; i++){
                if(ind>=n) break;
                tmp.push_back(arr[ind++]);
            }
            sort(tmp.begin(), tmp.end());
            ans.push_back(tmp);
            if(ind>=n) break;
        }
        return ans;
    }
};
