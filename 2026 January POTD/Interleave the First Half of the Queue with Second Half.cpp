class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n = q.size();
        queue<int>temp;
        
        for(int i=0;i<n/2;i++){
            temp.push(q.front());
            q.pop();
        }
        
        for(int i=0;i<n/2;i++){
           q.push(temp.front());
           temp.pop();
           q.push(q.front());
           q.pop();
        }
        
        return;
    }
};
