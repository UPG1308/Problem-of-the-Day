class Solution {
    static int singleElement(int[] arr, int N) {
        int ones = 0, twos = 0;
        for (int i : arr) {
            ones = (ones ^ i) & ~twos;
            twos = (twos ^ i) & ~ones;
        }
        return ones;
    }
}
