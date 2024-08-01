class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        int n=matrix.size(), m=matrix[0].size();
        int left=0, right=m-1, up=0, down=n-1;
        vector<int>ans;
        
        while(left<=right && up<=down){
            for(int col=left; col<=right && up<=down; col++){
                ans.push_back(matrix[up][col]);
            }
            up++;
            
            for(int row=up; row<=down && left<=right; row++){
                ans.push_back(matrix[row][right]);
            }
            right--;
            
            for(int col=right; col>=left && up<=down; col--){
                ans.push_back(matrix[down][col]);
            }
            down--;
            
            for(int row=down; row>=up && left<=right; row--){
                ans.push_back(matrix[row][left]);
            }
            left++;
        }
        return ans;
    }
};
