class Solution {
    int minRow(int n, int m, int a[][]) {
        // code here
        int count[] = new int[n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                count[i] += a[i][j];
            }
        }
        int idx = 0;
        for(int i = 0; i < n; i++){
            if(idx == 0 || count[i] < count[idx - 1]) idx = i + 1;
        }
        return idx;
    }
};
