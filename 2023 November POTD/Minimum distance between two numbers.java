
class Solution {
    int minDist(int a[], int n, int x, int y) {
        // code here
        int xdist = -1, ydist = -1, dist = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++){
            if(a[i] == x) xdist = i;
            if(a[i] == y) ydist = i;
            if(xdist != -1 && ydist != -1) dist = Math.min(dist, Math.abs(xdist - ydist));
        }
        return dist == Integer.MAX_VALUE? -1: dist;
    }
}
