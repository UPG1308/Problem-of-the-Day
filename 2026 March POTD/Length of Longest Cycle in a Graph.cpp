class Solution {
  public:
    void solve(unordered_map<int,vector<int>>&adj,int node,stack<int>&st,vector<int>&vis){
        if(vis[node] == 1) return;
        vis[node] = 1;
        for(auto it:adj[node]){
            solve(adj,it,st,vis);
        }
        st.push(node);
    }
    void solve1(int node, vector<int>&vis, unordered_map<int,vector<int>>&adj,vector<int>&v){
        if(vis[node] == 1) return;
        vis[node] = 1;
        for(auto it:adj[node]){
            solve1(it,vis,adj,v);
        }
        v.push_back(node);
    }
    int longestCycle(int V, vector<vector<int>>& edges) {
        // code here
        int n = edges.size();
        unordered_map<int,vector<int>>adj;
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        stack<int>st;
         unordered_map<int,vector<int>>adjT;
         for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adjT[v].push_back(u);
        }
        vector<int>vis(V,0);
        for(int i = 0;i<V;i++){
            if(vis[i] == 0){
                solve(adjT,i,st,vis);
            }
        }
        int ans = 0;
        for(int i = 0;i<V;i++){
            vis[i] = 0;
        }
        while(!st.empty()){
            int s = st.top();
            vector<int>v;
            st.pop();
            if(vis[s] == 0){
                solve1(s,vis,adj,v);
            }
            if(v.size() > 1 && ans < v.size()) ans = v.size();
            v.clear();
        }
        return ans == 0 ? -1 : ans;
    }
};
