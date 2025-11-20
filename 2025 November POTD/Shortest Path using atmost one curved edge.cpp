class Solution {
  public:
    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {
        // code here
        
        vector<vector<array<int, 3>>> adj(V);
    
        for(auto it: edges){
            int u = it[0], v = it[1], w1 = it[2], w2 = it[3];
            adj[u].push_back({v, w1,w2});
            adj[v].push_back({u, w1, w2});
        }
        
        vector<array<int, 2>> dist(V, {1e9, 1e9});
        
        dist[a][0] = 0;
        using T = array<int, 3>;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, 0, a});
        
        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int dis = it[0], used = it[1], node = it[2];
            
            if(dist[node][used] != dis) continue;
            
            for(auto i: adj[node]){
                int adjNode = i[0], w1 = i[1], w2 = i[2];
                
                
                    if(dist[adjNode][used] > dist[node][used] + w1){
                        dist[adjNode][used] = dist[node][used] + w1;
                        
                        pq.push({dist[adjNode][used], used, adjNode});
                    }
              
                if(!used){
                    if(dist[adjNode][1] > dist[node][0] + w2){
                        dist[adjNode][1] = dist[node][0] + w2;
                        
                        pq.push({dist[adjNode][1], 1, adjNode});
                    }
                }
            }
         }
        return min(dist[b][0], dist[b][1]);
    }
};
