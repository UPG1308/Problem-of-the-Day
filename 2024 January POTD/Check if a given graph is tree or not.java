class Solution {
    public boolean isTree(int n, int m, ArrayList<ArrayList<Integer>> edges) 
    {
        // code here
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i =0;i < n; i++) adj.add(new ArrayList<>());
        for(ArrayList<Integer> edge: edges){
            adj.get(edge.get(0)).add(edge.get(1));
            adj.get(edge.get(1)).add(edge.get(0));
        }
        boolean vis[] = new boolean[n];
        for(int i = 0; i < n; i++){
            if(!vis[i]) {
                if(!dfs(i, -1, adj, vis)) return false;
            }
        }
        if(m != n - 1) return false;
        return true;
    }
    
    public boolean dfs(int node, int parent, ArrayList<ArrayList<Integer>> adj, boolean vis[]){
        vis[node] = true;
        for(int adjNode: adj.get(node)){
            if(!vis[adjNode]) {
                if(!dfs(adjNode, node, adj, vis)) return false;
            }
            else if(adjNode != parent) return false;
        }
        return true;
    }
}
