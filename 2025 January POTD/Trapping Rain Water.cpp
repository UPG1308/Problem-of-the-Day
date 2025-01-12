class Solution {
  public:
    int maxWater(vector<int>& arr) {
        stack<int> st;  
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
           
            // Pop all items smaller than arr[i]
            while (!st.empty() && arr[st.top()] < arr[i]) {          
                
                int pop_height = arr[st.top()];
                st.pop();
              
                if (st.empty())
                    break;
    
                // arr[i] is the next greater for the removed item
                // and new stack top is the previous greater 
                int distance = i - st.top() - 1;
              
                // Take the minimum of two heights (next and prev greater)
                // and find the amount of water that we can fill in all
                // bars between the two
                int water = min(arr[st.top()], arr[i]) - pop_height;
    
                res += distance * water;
            }
            st.push(i);
        }
        return res;
    }
};
