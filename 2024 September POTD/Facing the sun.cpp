class Solution {
  public:
    // Returns count buildings that can see sunlight
    int countBuildings(vector<int> &height) {
        // code here
        int count = 0;
        
        int Maximum = INT_MIN;
        
        for(const int& x : height){
            
            if(Maximum < x){
                count++;
                Maximum = x;
            }
        }
        
        return count;
    }


};
