class Solution {
  public:
    int boundaryCheck(int r, int c, int n, int m){
        return r >= 0 && r < n && c >= 0 && c < m;
    }
  
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        int delRow[] = {+1, 0, -1, 0};
        int delCol[] = {0, -1, 0, +1};
        
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        using T = array<int, 3>;
        
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, 0, 0});
        
        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int dis = it[0], row = it[1], col = it[2];
            
            if(dist[row][col] != dis) continue;
            
            for(int i = 0; i < 4; ++i){
                int r = row + delRow[i];
                int c = col + delCol[i];
                
                if(boundaryCheck(r, c, n, m)){
                    int val = max(dist[row][col], abs(mat[row][col] - mat[r][c]));
                    
                    if(dist[r][c] > val){
                        dist[r][c] = val;
                        pq.push({val, r, c});
                    }
                }
            }
        }
        
        return dist[n - 1][m - 1];
    }
};
