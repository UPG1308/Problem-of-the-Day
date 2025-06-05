class Solution {
  public:
    
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        
        vector<vector<int>> adj(V);
        for(vector<int> e: edges) adj[e[0]].push_back(e[1]);
        
        vector<int> dist(V), indegree(V);
        queue<int> q;
        dist[src] = 1;
        for(vector<int> e: edges) indegree[e[1]]++;
        for(int i = 0; i < V; ++i){
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int adjNode: adj[node]){
                if(--indegree[adjNode] == 0){
                    q.push(adjNode);
                }
                dist[adjNode] += dist[node];
            }
        }
        return dist[dest];
    }
};
