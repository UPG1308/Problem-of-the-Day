void rotate(vector<vector<int> >& mat) {
    // Your code goes here
    int n = mat.size();
    for(int i = 0; i < n; ++i){
        int j = 0, k = n - 1;
        while(j < k)swap(mat[i][j++], mat[i][k--]);
    }
    
    for(int j = n - 1; j >= 0; --j){
        for(int i = 0; i < n - 1 - j; ++i) swap(mat[i][j], mat[n - 1 - j][n - 1 - i]);
    }
}
