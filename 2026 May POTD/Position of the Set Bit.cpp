class Solution {
  public:
    int findPosition(int n) {
        // code here
         if((n & n-1) !=0)
            return -1;
        return (int)log2(n) + 1; 
    }
};
