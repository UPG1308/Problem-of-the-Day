class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);
        for(auto it: edges){
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        
        vector<int> dist(V, 1e9), ways(V, 0);
        dist[0] = 0, ways[0] = 1;
        
        using T = pair<int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        
        pq.push(make_pair(0, 0));
        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int dis = it.first, node = it.second;
            
            if(dist[node] != dis) continue;
            
            for(auto itr: adj[node]){
                int adjNode = itr.first, w = itr.second;
                if(dist[adjNode] > dist[node] + w){
                    dist[adjNode] = dist[node] + w;
                    ways[adjNode] = ways[node];
                    pq.push(make_pair(dist[adjNode], adjNode));
                }
                else if(dist[adjNode] == dist[node] + w){
                    ways[adjNode] += ways[node];
                }
            }
        }
        
        return ways[V - 1];
    }
};
