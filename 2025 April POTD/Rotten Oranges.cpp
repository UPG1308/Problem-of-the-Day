class Solution {
  public:
    bool boundaryCheck(int row, int col, int n, int m){
        return row >= 0 && row < n && col >= 0 && col < m;
    }
    
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int n = mat.size(), m = mat[0].size();
        deque<pair<int, int>> q;
        int cnt = 0;
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(mat[i][j] == 2) q.push_back({i, j});
                else if(mat[i][j] == 1) cnt++;
            }
        }
        
        if(cnt == 0) return 0;
        vector<vector<int>> vis(n, vector<int>(m));
        
        
        int delRow[] = {+1, 0, -1, 0};
        int delCol[] = {0, -1, 0, +1};
        
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto f = q.front();
                int row = f.first, col = f.second;
                q.pop_front();
                
                for(int i = 0; i < 4; ++i){
                    int r = row + delRow[i];
                    int c = col + delCol[i];
                    
                    if(boundaryCheck(r, c, n, m) && mat[r][c] == 1 && !vis[r][c]){
                        vis[r][c] = 1;
                        cnt--;
                        q.push_back({r, c});
                    }
                }
            }
            time++;
        }
        
        return cnt == 0? time - 1: -1;
    }
};
