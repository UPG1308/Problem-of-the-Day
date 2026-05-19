class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        
        vector<int> vis(1001, -1);
        queue<int> q;
        q.push(start);
        vis[start] = 0;
        
        while(!q.empty()){
            int node = q.front(); q.pop();
            for(int i: arr){
                int nextNode = (node * i) % 1000;
                if(vis[nextNode] == -1){
                    vis[nextNode] = vis[node] + 1;
                    q.push(nextNode);
                }
            }
        }
        return vis[end];
    }
};
