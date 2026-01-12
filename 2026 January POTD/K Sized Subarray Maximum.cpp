class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        deque<int> dq;
        vector<int> ans(n - k + 1);
        for(int i = 0; i < n; ++i){
            while(!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
            while(!dq.empty() && dq.front() <= i - k) dq.pop_front();
            dq.push_back(i);
            if(i >= k - 1) ans[i - k + 1] = arr[dq.front()];
        }
        
        return ans;
    }
};
