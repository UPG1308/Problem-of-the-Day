class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        for(int j = 0; j < n; j++){
            int zeroIndex = -1;
            for(int i = 0; i < n; i++){
                if(mat[i][j] == 0 and zeroIndex != -1) {zeroIndex = -1; break;}
                if(mat[i][j] == 0) zeroIndex = i;
            }
            // cout<<" "<<j<<" "<< zeroIndex<<"\n";
            if(zeroIndex != -1){
                
                for(int k = 0; k < n; k++){
                    if(mat[zeroIndex][k] == 1) break;
                    else if(k == n - 1) return zeroIndex;
                }
            }
        }
        return -1;
    }
};
