class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // Here i am using sliding window concept with deque(double ended queue) data structure. it will take O(n) time.
        int n = arr.size();
        vector<int> max_arr;
        deque<int> dq;

        for (int i = 0; i < n; i++) {
           // Remove elements out of the current window
            if (!dq.empty() && dq.front() < i - k + 1) {
               dq.pop_front();
            }

           // Remove elements smaller than the current element
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                 dq.pop_back();
            }

           // Add the current element to the deque
            dq.push_back(i);

            // Start adding results to max_arr after we have processed the first 'k' elements
            if (i >= k - 1) {
               max_arr.push_back(arr[dq.front()]);
            }
        }

        return max_arr;
    }
};
