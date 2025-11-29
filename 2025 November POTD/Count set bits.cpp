class Solution {
  public:
    
    int countSetBits(int n) {
    int count = 0;
    for (int i = 0; (1 << i) <= n; i++) {
        int cycle = 1 << (i + 1);
        int fullCycles = (n + 1) / cycle;
        count += fullCycles * (1 << i);

        int remainder = (n + 1) % cycle;
        count += max(0, remainder - (1 << i));
    }
    return count;
}
};
