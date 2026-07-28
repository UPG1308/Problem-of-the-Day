class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);
        for(auto it: edges){
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        
        deque<int> dq;
        dq.push_back(src);
        while(!dq.empty()){
            int node = dq.front(); dq.pop_front();
            for(auto [adjNode, w]: adj[node]){
                if(dist[adjNode] > dist[node] + w){
                    dist[adjNode] = dist[node] + w;
                    if(w == 1) dq.push_front(adjNode);
                    else dq.push_back(adjNode);
                }
            }
        }
        
        return dist[dest] == 1e9? -1: dist[dest];
    }
};
