#include <bits/stdc++.h> 

using namespace std; 

class Solution { 
    public: 
        int minStepToReachTarget(vector < int > & knightPos, vector < int > & targetPos, int n) { 
            vector < vector < bool >> vis(n + 1, vector < bool > (n + 1, false)); 
            if (targetPos == knightPos) { 
                return 0; 
            } 

            int level = 0; 
            pair < int, int > target = {targetPos[0], targetPos[1]}; 
            queue < pair < int, int >> q; 
            q.push({knightPos[0], knightPos[1]}); 
            vis[knightPos[0]][knightPos[1]] = true; 

            int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2}; 
            int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1}; 

            while (!q.empty()) { 
                int sz = q.size(); 
                level++; 

                while (sz--) {
                    pair < int, int > curr = q.front(); 
                    q.pop(); 

                    for (int i = 0; i < 8; i++) { 
                        int nx = dx[i] + curr.first; 
                        int ny = dy[i] + curr.second; 

                        if(nx >= 1 && nx <= n && ny >= 1 && ny <= n && !vis[nx][ny]) { 
                            if( target.first == nx && target.second == ny ) { 
                                return level; 
                            } 
                            vis[nx][ny] = true;
                            q.push({nx, ny}); 
                        } 
                    } 
                }
            } 

            return -1; 
        } 
}; 
