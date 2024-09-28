class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int>pq;
        
        int n=arr.size();
        for(int i=0; i<n; i++){
            if(pq.size()<k){
                pq.push(arr[i]);
            }else if(!pq.empty() && pq.top()>arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};