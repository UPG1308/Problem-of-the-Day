
  public:
    string armstrongNumber(int n) {
        // code here
        long sum = 0;
        int val = n;
        while(val > 0){
            int ld = val % 10;
            sum += ld * ld * ld;
            val = val / 10;
        }
        return n == sum?"true":"false";
    }
};
