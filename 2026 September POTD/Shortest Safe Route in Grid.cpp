class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat) {
        // code here
        int inf = 1e9;
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, inf));
        int delRow[] = {+1, 0, -1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        auto boundaryCheck = [&](int r, int c){
            return r >= 0 && r < n && c >= 0 && c < m;
        };
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(mat[i][j] == 0){
                    dist[i][j] = -1;
                    for(int k = 0; k < 4; ++k){
                        int r = i + delRow[k];
                        int c = j + delCol[k];
                        if(boundaryCheck(r, c)) dist[r][c] = -1;
                    }
                }
            }
        }
        queue<array<int, 2>> q;
        for(int i = 0; i < n; ++i){
            if(dist[i][0] == -1) continue;
            dist[i][0] = 1;
            q.push({i, 0});
        }
        
        while(!q.empty()){
            auto [row, col] = q.front(); q.pop();
            for(int i = 0; i < 4; ++i){
                int r = row + delRow[i];
                int c = col + delCol[i];
                if(!boundaryCheck(r, c)) continue;
                if(dist[r][c] == -1) continue;
                if(dist[r][c] > dist[row][col] + 1) {
                    dist[r][c] = dist[row][col] + 1;
                    q.push({r, c});
                }
            }
        }
        int ans = inf;
        for(int i = 0; i < n; ++i){
            if(dist[i][m - 1] == -1) continue;
            ans = min(ans, dist[i][m - 1]);
        }
        
        return ans == inf? -1: ans;
    }
};
