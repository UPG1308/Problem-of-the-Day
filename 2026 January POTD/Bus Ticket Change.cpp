class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int n = arr.size();
        int five = 0, ten = 0;
        
        for(auto num: arr){
            if(num == 5) five++;
            else if(num == 10) {
                ten++;
                if(five == 0) return false;
                else five--;
            }
            else {
                if(ten > 0 && five > 0) ten--, five--;
                else if(five > 2) five -= 3;
                else return false;
            }
        }
        
        return true;
    }
};
