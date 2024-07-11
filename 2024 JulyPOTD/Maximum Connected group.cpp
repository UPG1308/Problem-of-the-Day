class UnionFind{
public:
    vector<int> size, parent;
    UnionFind(int n){
        for(int i = 0;i <= n; i++){
            size.push_back(1);
            parent.push_back(i);
        }
    }
    
    int Find(int u){
        if(parent[u] == u) return u;
        return parent[u] = Find(parent[u]);
    }
    
    void Union(int u, int v){
        int upar = Find(u);
        int vpar = Find(v);
        if(upar == vpar) return;
        if(size[upar] > size[vpar]){
            size[upar] += size[vpar];
            parent[vpar] = upar;
        }
        else{
            size[vpar] += size[upar];
            parent[upar] = vpar;
        }
    }
};

class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        UnionFind* uf = new UnionFind(n * n);
        int maxValue = 0;
        bool zeroFound = false;
        int Row[] = {+1, 0, -1, 0};
        int Col[] = {0, +1, 0, -1};
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 0) {zeroFound = true; continue;}
                for(int i = 0; i < 4; i++){
                    int newRow = row + Row[i];
                    int newCol = col + Col[i];
                    if(boundaryCheck(newRow, newCol, n) && grid[newRow][newCol] == 1)
                        uf -> Union((row * n) + col, (newRow * n) + newCol);
                }
            }
        }
        if(!zeroFound) return n * n;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1) continue;
                int currSize = 0;
                set<int> parent;
                for(int i = 0; i < 4; i++){
                    int newRow = row + Row[i];
                    int newCol = col + Col[i];
                    if(boundaryCheck(newRow, newCol, n) and grid[newRow][newCol]){
                        int par = uf -> Find(newRow * n + newCol);
                        if(!(parent.find(par) != parent.end())){
                            currSize += uf -> size[par];
                            parent.insert(par);
                        }
                    } 
                }
                // cout <<"row = "<<row<<" col = "<<col<<" value = "<<currSize<<'\n';
                maxValue = max(maxValue, currSize + 1);
            }
        }
        return maxValue;
    }
    
    bool boundaryCheck(int row, int col, int n){
        return row >= 0 && row < n && col >= 0 && col < n;
    }
};
