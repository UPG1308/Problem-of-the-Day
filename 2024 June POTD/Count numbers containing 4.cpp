class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        if(n < 4) return 0;
        int count = 0;
        for(int i = 4; i <= n; i++){
            int temp = i;
            while(temp > 3){
                int digit = temp%10;
                if(digit == 4){
                    count++;
                    break;
                }
                temp = temp / 10;
            }
        }
        return count;
    }
};
