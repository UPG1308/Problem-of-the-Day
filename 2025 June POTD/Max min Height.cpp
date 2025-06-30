class Solution {
  public:
    bool check(long long height, vector<int> &arr, int k, int w){
        
        queue<pair<int, long long>> q;
        long long currentHeight = 0;
        for(int i = 0; i < arr.size(); ++i){
            if(!q.empty() && q.front().first <= i) {
                currentHeight -= q.front().second;
                q.pop();
            }
            
            if(arr[i] + currentHeight < height){
                long long req = height - (arr[i] + currentHeight);
                if(req > k) return false;
                k -= req;
                currentHeight += req;
                q.push({i + w, req});
            }
        }
        return true;
    }
  
    int maxMinHeight(vector<int> &arr, int k, int w) {
        // code here
            long long l = -1, r = 1e17;
            while(r - l > 1){
                int m = l + (r - l)/2;
                if(check(m, arr, k, w)) l = m;
                else r = m;
            }
            return l;
    }
};
