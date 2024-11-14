class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = arr.size(), i = 0;
        for(i = 0; i < n; ++i){
            pq.push(arr[i]);
            if(i >= k){
                arr[i - k] = pq.top();
                pq.pop();
            }
        }
        while(i - k < n){
            arr[i - k] = pq.top();
            pq.pop();
            i++;
        }
    }
};
