class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> adj[N];
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> dist(N, -1);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; ++i){
                int node = q.front();
                q.pop();
                for(int adjNode: adj[node]){
                    if(dist[adjNode] == -1){
                        dist[adjNode] = dist[node] + 1;
                        q.push(adjNode);
                    }
                }
            }
        }
        return dist;
    }
};
