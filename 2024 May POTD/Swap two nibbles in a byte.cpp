class Solution {
  public:
    int swapNibbles(int n) {
        // code here
         return (n&240)>>4|(n&15)<<4;
    }
};
